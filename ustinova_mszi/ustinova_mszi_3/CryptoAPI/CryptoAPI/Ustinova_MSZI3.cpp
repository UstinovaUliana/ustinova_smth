
#include "pch.h"
#include "framework.h"
#include "Ustinova_MSZI3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

string pass_;

#pragma comment(lib, "crypt32.lib")

CWinApp theApp;

class CryptoAPI
{
	HCRYPTPROV m_hCP = NULL;
	HCRYPTKEY m_hExchangeKey = NULL;
	HCRYPTKEY m_hSessionKey = NULL;
	HCRYPTKEY m_hExportKey = NULL;
public:

	HCRYPTKEY GetExchangeKey()
	{
		return m_hExchangeKey;
	}

	HCRYPTKEY GetSessionKey()
	{
		return m_hSessionKey;
	}

	HCRYPTKEY GetExportKey()
	{
		return m_hExportKey;
	}

	CryptoAPI()
	{
		if (!CryptAcquireContext(&m_hCP, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))	// использование временных ключей, не сохраняющихся в контейнере
			PrintError();
//		if (!CryptAcquireContext(&m_hCP, "My Container", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
//		{
//			if (GetLastError() == NTE_BAD_KEYSET)
//			{
//				if (!CryptAcquireContext(&m_hCP, "My Container", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_NEWKEYSET))
//					PrintError();
//			}
//		}
	}
	
	~CryptoAPI()
	{
		DestroyKeys();
		if (m_hCP)
		{
			if (!CryptReleaseContext(m_hCP, 0))
				PrintError();
		}
	}

	void GenKeyPair()
	{
		if (!CryptGenKey(m_hCP, CALG_RSA_KEYX, CRYPT_EXPORTABLE, &m_hExchangeKey))
			PrintError();
	}

	void GenSessionKey()
	{
		if (!CryptGenKey(m_hCP, CALG_AES_256, CRYPT_EXPORTABLE, &m_hSessionKey))
			PrintError();
	}

	void GenExportKey(const string& sPassword)
	{
		HCRYPTHASH hHash;
		if (!CryptCreateHash(m_hCP, CALG_SHA_256, NULL, 0, &hHash))
		{
			PrintError();
			return;
		}
		if(!CryptHashData(hHash, (BYTE*)sPassword.c_str(), sPassword.length(), 0))
		{
			PrintError();
			return;
		}

		if (!CryptDeriveKey(m_hCP, CALG_AES_256, hHash, CRYPT_EXPORTABLE, &m_hExportKey))
			PrintError();

		CryptDestroyHash(hHash);
	}

	void DestroyKey(HCRYPTKEY& hKey)
	{
		if (hKey)
		{
			if (!CryptDestroyKey(hKey))
				PrintError();
			hKey = NULL;
		}
	}

	void DestroyKeys()
	{
		DestroyKey(m_hExchangeKey);
		DestroyKey(m_hSessionKey);
		DestroyKey(m_hExportKey);
	}

	void DoExportKey(vector<char>& v, HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwType)
	{
		DWORD dwLen = 0;
		if (!CryptExportKey(hKey, hExpKey, dwType, 0, NULL, &dwLen))
		{
			PrintError();
			return;
		}
		v.resize(dwLen);
		if (!CryptExportKey(hKey, hExpKey, dwType, 0, (BYTE*)v.data(), &dwLen))
			PrintError();
		v.resize(dwLen);		// поскольку для некоторых ключей реальный размер экспортированных данных 
								// может быть меньше размера, необходимого для экспорта
	}

	void DoImportKey(vector<char>& v, HCRYPTKEY& hKey, HCRYPTKEY hPubKey, DWORD dwType)
	{
		if (!CryptImportKey(m_hCP, (BYTE*)v.data(), v.size(), hPubKey, CRYPT_EXPORTABLE, &hKey))
			PrintError();
	}

	void ExportPublicKey(vector<char>& v)
	{
		DoExportKey(v, m_hExchangeKey, NULL, PUBLICKEYBLOB);
	}

	void ExportPrivateKey(vector<char>& v)
	{
		DoExportKey(v, m_hExchangeKey, m_hExportKey, PRIVATEKEYBLOB);
	}

	void ExportSessionKey(vector<char>& v)
	{
		DoExportKey(v, m_hSessionKey, m_hExchangeKey, SIMPLEBLOB);
	}

	void ImportPublicKey(vector<char>& v)
	{
		DoImportKey(v, m_hExchangeKey, NULL, PUBLICKEYBLOB);
	}

	void ImportPrivateKey(vector<char>& v)
	{
		DoImportKey(v, m_hExchangeKey, m_hExportKey, PRIVATEKEYBLOB);
	}

	void ImportSessionKey(vector<char>& v)
	{
		DoImportKey(v, m_hSessionKey, NULL, SIMPLEBLOB);
	}

	void EncryptData(ifstream& in, ofstream& out, DWORD dwSize, HCRYPTKEY hKey = NULL, bool bRSA = false)
		// CryptGetKeyParam с KP_BLOCKLEN возвращает размер блока в битах, 
		// для большинства алгоритмов можно использовать кратное значение,
		// но RSA требует точного соответствия длине блока в байтах,
		// причем 11 байт нужны для обязательного заполнителя (padding)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
			dwBlockLen -= 11;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			in.read(v.data(), dwBlockLen);
			DWORD dwRead = (DWORD)in.gcount();
			dwDone += dwRead;
			bDone = (dwDone == dwSize);
			dwDataLen = dwRead;
			if (!CryptEncrypt(hKey, NULL, bDone, 0, NULL, &dwDataLen, 0))
				PrintError();
			if (dwDataLen > v.size())
				v.resize(dwDataLen);
			if (!CryptEncrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead, v.size()))
				PrintError();
			out.write(v.data(), dwRead);
		}
	}

	void DecryptData(ifstream& in, ofstream& out, DWORD dwSize, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			in.read(v.data(), dwBlockLen);
			DWORD dwRead = (DWORD)in.gcount();
			dwDone += dwRead;
			bDone = (dwDone == dwSize);
			if (!CryptDecrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead))
				PrintError();
			out.write(v.data(), dwRead);
		}
	}

	void EncryptData(vector<char>& vIn, vector<char>& vOut, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
			dwBlockLen -= 11;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			DWORD dwRead = min(dwBlockLen, vIn.size() - dwDone);
			memcpy(v.data(), vIn.data() + dwDone, dwRead);
			dwDone += dwRead;
			bDone = (dwDone == vIn.size());
			dwDataLen = dwRead;
			if (!CryptEncrypt(hKey, NULL, bDone, 0, NULL, &dwDataLen, 0))
				PrintError();
			if (dwDataLen > v.size())
				v.resize(dwDataLen);
			if (!CryptEncrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead, v.size()))
				PrintError();
			vOut.insert(vOut.end(), v.begin(), v.begin() + dwRead);
		}
	}

	void DecryptData(vector<char>& vIn, vector<char>& vOut, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			DWORD dwRead = min(dwBlockLen, vIn.size() - dwDone);
			memcpy(v.data(), vIn.data() + dwDone, dwRead);
			dwDone += dwRead;
			bDone = (dwDone == vIn.size());
			if (!CryptDecrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead))
				PrintError();
			vOut.insert(vOut.end(), v.begin(), v.begin() + dwRead);
		}
	}
	//!
	void GenKeys(string pass)
	{
		GenKeyPair(); //generate exchange
		GenExportKey(pass);//generate export на основе пароля
		{
			vector<char> v;
			//экспорт закрытого ключа в вектор+шифровка закрытого при экспорте при помощи export ключа
			ExportPrivateKey(v);
			ofstream out("private.key.txt", ios::binary);
			out.write(v.data(), v.size());
		}
		{
			vector<char> v;
			//экспорт открытого ключа в вектор
			ExportPublicKey(v);
			ofstream out("public.key.txt", ios::binary);
			out.write(v.data(), v.size());
		}
		cout << "Ключи сгенерированы.\n";
	}

	void ImportPrivateKeyInit(string pass)
	{
		GenExportKey(pass);
		ifstream in("private.key.txt", ios::binary);
		vector v(istreambuf_iterator<char>{in}, {});
		ImportPrivateKey(v);
	}
	void ImportPublicKeyInit()
	{
		ifstream in("public.key.txt", ios::binary);
		vector v(istreambuf_iterator<char>{in}, {});
		ImportPublicKey(v);
	}
	void EncryptFileInit(string infilename, string outfilename)
	{
		GenSessionKey();
		vector<char> v1;
		vector<char> v2;
		//экспорт сессионного ключа в вектор
		ExportSessionKey(v1);
		//шифруем сессионный с помощью RSA и ExchangeKey
		//зашифр ключ в векторе2
		EncryptData(v1, v2, GetExchangeKey(), true);

		ifstream in(infilename, ios::binary);
		ofstream out(outfilename, ios::binary);
		//склеивание зашифрованных данных и сессионного ключа в один файл
		out << v2.size();
		out << ";";
		out.write(v2.data(), v2.size());
		//шифровка файла с помощью сессионного ключа без рса
		//зашифр файл в файле out
		//по умолчанию шифр сессионным
		EncryptData(in, out, (DWORD)filesystem::file_size(infilename));
		DestroyKeys();
		cout << "Файл зашифрован.\n";
	}

	void DecryptFileInit(string infilename, string outfilename)
	{
		ifstream in(infilename, ios::binary);
		string slength;
		while (true)
		{
			char s;
			in.get(s);
			if (s == ';')
				break;
			slength.push_back(s);
		}
		vector<char> v1;
		int length = stoi(slength);
		while (length--)
		{
			char s;
			in.get(s);
			v1.push_back(s);
		}
		vector<char> v2;
		DecryptData(v1, v2, GetExchangeKey(), true);
		ImportSessionKey(v2);
		vector<char> v3;
		vector<char> v4;
		while (true)
		{
			char s;
			in.get(s);
			if (in.eof())
				break;
			v3.push_back(s);
		}
		//расшифр файл сессионным без рса
		DecryptData(v3, v4);
		ofstream out(outfilename, ios::binary);
		out.write(v4.data(), v4.size());
		DestroyKeys();
		cout << "Файл расшифрован.\n";
	}
	void generate()
	{
		string pass;
		cout << "Введите пароль: ";
		cin.ignore(1, '\n');
		getline(cin, pass);
		pass_ = pass;
		GenKeys(pass);
	}
	//!
};

void CryptoTest()
{
	{
		CryptoAPI crypto;

		crypto.GenKeyPair();
		crypto.GenSessionKey();
		crypto.GenExportKey("12345");

		{
			vector<char> v;
			crypto.ExportPrivateKey(v);
			ofstream out("private.key", ios::binary);
			out.write(v.data(), v.size());
		}

		{
			vector<char> v;
			crypto.ExportPublicKey(v);
			ofstream out("public.key", ios::binary);
			out.write(v.data(), v.size());
		}

		// CryptExportKey не шифрует, а подписывает сессионные ключи, поэтому лучше использовать следующий блок
		{
			vector<char> v;
			crypto.ExportSessionKey(v);
			ofstream out("session.key", ios::binary);
			out.write(v.data(), v.size());
		}

		{
			vector<char> v1;
			vector<char> v2;
			crypto.ExportSessionKey(v1);
			crypto.EncryptData(v1, v2, crypto.GetExchangeKey(), true);
			ofstream out("session.enc.key", ios::binary);
			out.write(v2.data(), v2.size());
		}

		{
			ifstream in("CryptoAPI.cpp", ios::binary);
			ofstream out("CryptoAPI.cpp.enc", ios::binary);
			crypto.EncryptData(in, out, (DWORD)filesystem::file_size("CryptoAPI.cpp"));
		}
	}

	
	{
		CryptoAPI crypto;

		crypto.GenExportKey("12345");
		{
			ifstream in("private.key", ios::binary);
			vector v(istreambuf_iterator<char>{in}, {});
			crypto.ImportPrivateKey(v);
		}

		{
			ifstream in("public.key", ios::binary);
			vector v(istreambuf_iterator<char>{in}, {});
			crypto.ImportPublicKey(v);
		}

		{
			ifstream in("session.key", ios::binary);
			vector v(istreambuf_iterator<char>{in}, {});
			crypto.ImportSessionKey(v);
		}

		{
			ifstream in("session.enc.key", ios::binary);
			vector v1(istreambuf_iterator<char>{in}, {});
			vector<char> v2;
			crypto.DecryptData(v1, v2, crypto.GetExchangeKey(), true);
			crypto.ImportSessionKey(v2);
		}

		{
			ifstream in("CryptoAPI.cpp.enc", ios::binary);
			ofstream out("CryptoAPI.cpp.dec", ios::binary);
			crypto.DecryptData(in, out, (DWORD)filesystem::file_size("CryptoAPI.cpp.enc"));
		}
	}
}

int main()
{     
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: code your application's behavior here.
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			//!
			//CryptoTest();
			CryptoAPI crypto;
			while (true)
			{
				cout << "1. Сгенерировать и сохранить публичный и приватный ключи.\n"
					<< "2. Зашифровать файл.\n"
					<< "3. Расшифровать файл.\n"
					<< "0. Выход.\n";
				cout << "Выберите действие: ";
				unsigned int choice;
				cin >> choice;
				switch (choice)
				{
				case 0:
				{
					return nRetCode;
				}
				case 1:
				{
					crypto.generate();
					break;
				}
				case 2:
				{
					string infilename, outfilename;
					cout << "\nВведите название файла для считывания: ";
					cin >> infilename;
					cout << "\nВведите название файла для сохранения: ";
					cin >> outfilename;
					crypto.ImportPublicKeyInit();
					crypto.EncryptFileInit(infilename, outfilename);
					break;
				}
				case 3:
				{
					string infilename, outfilename, pass;
					pass_ = "12345";
					crypto.ImportPrivateKeyInit(pass_);
					cout << "\nВведите название файла для считывания: ";
					cin >> infilename;
					cout << "\nВведите название файла для сохранения: ";
					cin >> outfilename;
					crypto.DecryptFileInit(infilename, outfilename);
					break;
				}
				}
			}
			//!
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}
