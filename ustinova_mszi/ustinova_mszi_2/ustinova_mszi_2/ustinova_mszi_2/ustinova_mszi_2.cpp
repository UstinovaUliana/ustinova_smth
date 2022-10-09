#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm> 
#include <set>
using namespace std;

void decoding() {
	// ifstream in("file.txt", ios::binary);
	// vector<char> v((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	map<char, float> etChastoty;

	float frequency;
	string etFileName;
	multimap<char, int> etLetters;

	cout << "Введите название файла с эталонным текстом: \n";
	cin >> etFileName;
	ifstream fin(etFileName, ios::binary);
	vector<char> etText((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>()); //эталонный текст
	fin.close();
	

	//for (auto letter : etText) {
	//	if (etChastoty.find(letter)!= etChastoty.end()) {
	//		etLetters.emplace(letter, (int)letter);
	//		etChastoty.emplace(letter, 1);
	//	}
	//	else {
	//		etChastoty.find(letter)->second += 1;
	//		
	//	}
	//}
	for (auto i : etText)
		etLetters.insert(pair<char, int>(i, (int)i));

	int x1 = etLetters.size();
	for (int i = 0; i <= 255; i++) {
		frequency = etLetters.count(i);
		if (frequency != 0)
			etChastoty.insert(pair<char, float>(i, frequency));
	}

	/*sort(etChastoty.begin(), etChastoty.end());
	int i = 0;
	for (map <char, float> ::iterator it = etChastoty.begin(); i < 6; i++, it++) cout << it->second << " : " << it->second <<"\n";*/
	/*for (auto i : text)
		letters.insert(pair<char, int>(i, (int)i));*/


		/*for (int i = 0; i <= 255; i++) {
			frequency = letters.count(i) / x;
			if (frequency != 0)
				chastoty.insert(pair<char, float>(i, frequency));
		}*/

		//return ref_text;

	int keySize, j;
	string codedFileName, outFileName;
	
	char s;
	multimap<char, int> table;
	map<char, float> codedChastoty; //анализ группы зашифрованного текста
	vector<char> sym_in_groups; //символы в группах
	vector<int> keyword; //смещение

	cout << "Введите название файла с зашифрованным текстом\n";
	cin >> codedFileName;
	ifstream fin1(codedFileName, ios::binary);
	vector<char> codedText((istreambuf_iterator<char>(fin1)), istreambuf_iterator<char>()); //зашифрованный текст
	fin.close();

	//m(n - 1)is* L = L * summ(pi ^ 2)(n - m) + n(m - 1)
	//	m(n - 1)is * L + L * summ(pi ^ 2) * m - nm = L * summ(pi ^ 2) * n - n
	//	m((n - 1) * is * L + L * summ(pi ^ 2) - n) = n(L * summ(pi ^ 2) - 1)
	//	m = (n * (L * summ(pi ^ 2) - 1)) / ((n - 1) * is * L + L * summ(pi ^ 2) - n)
	int N = codedText.size();
	//sort(text.begin(), text.end());
	int L = 256;
	/*for (auto i : codedText)
		table.insert(pair<char, int>(i, (int)i));

	*/
	//for (int i = 0; i <= 255; i++) {
	//	frequency = table.count(i);
	//	if (frequency != 0)
	//		codedChastoty.insert(pair<char, float>(i, frequency));
	//}
	//float is=0;
	//for (auto fi : codedChastoty) {
	//	is += fi.second * (fi.second - 1) / (N * (N - 1));
	//}
	////is = is / (N * (N - 1));
	//cout << is<<endl;
	//float A=0;
	//for (auto fi : codedChastoty) {
	//	A += fi.second * fi.second / (N * N);
	//}
	//keySize = (N * (L * A - 1)) / ((N - 1) * is * L + L * A - N);
	//cout << keySize<<endl;
	keySize = 10;
	/*cout << "Введите длину ключа\n";
	cin >> keySize*/;
	int letterPos = keySize;
	/*codedChastoty.clear();
	table.clear();*/
	
	map<char, float> etChastoty1;
	vector<char> sym_in_groups1; //символы в группах
	for (int i = 0; i < keySize; i++) {
		for (int j = keySize - letterPos; j < codedText.size(); j += keySize) {
			s = codedText.at(j);
			sym_in_groups.push_back(s);
		}
		for (auto j : sym_in_groups)
			table.insert(pair<char, int>(j, (int)j));
		for (int j = 0; j <= 255; j++) {
			frequency = table.count(j);
			if (frequency != 0)
				codedChastoty.insert(pair<char, float>(j, frequency));
		}
		sym_in_groups.clear();
		table.clear();
		for (int j = keySize - letterPos; j < etText.size(); j += keySize) {
			s = etText.at(j);
			sym_in_groups.push_back(s);
		}
		for (auto j : sym_in_groups)
			table.insert(pair<char, int>(j, (int)j));
		for (int j = 0; j <= 255; j++) {
			frequency = table.count(j);
			if (frequency != 0)
				etChastoty1.insert(pair<char, float>(j, frequency));
		}
		auto maxCodedInGroup = max_element(codedChastoty.begin(), codedChastoty.end(), [](const pair<char, float>& p1, const pair<char, float>& p2) {return p1.second < p2.second; });
		auto maxInGroup = max_element(etChastoty1.begin(), etChastoty1.end(), [](const pair<char, float>& p1, const pair<char, float>& p2) {return p1.second < p2.second; });
		keyword.push_back(maxCodedInGroup->first - maxInGroup->first);
		cout << char(keyword[i]);
		letterPos--;
		sym_in_groups.clear();
		codedChastoty.clear();
		etChastoty1.clear();
		table.clear();
	}

	cout << "Введите название файла, куда сохранить расшифрованный текст: \n";
	cin >> outFileName;
	letterPos = 0;
	ofstream fout(outFileName, ios::binary);
	for (auto j : codedText) {
		s = j - char(keyword[letterPos % keySize]);
		fout << s;
		letterPos++;
	}
	fout.close();
	cout << "\nСохранено!\n";
}

int main()
{

	setlocale(LC_ALL, "Russian");
	/*while (true) {
		cout << "1. Выбрать эталонный текст\n";
		cout << "2. Дешифровать текст\n";
		cout << "0. Выход из программы\n";
		int com;
		cin >> com;
		switch (com) {
		case 1: {
			v = analyze(analyze_ref);
			break;
		}
		case 2: {
			if (v.size() == 0) {
				cout << "Отсутствует анализ текста!\n";
				break;
			}
			decryption(v, analyze_ref);
			break;
		}
		case 3:
			return 0;
		}
		default: {


		}
	}*/
	while (true) {
		cout << "1. дешифровка\n";
		cout << "0. Выход из программы\n";
		int com;
		cin >> com;
		switch (com) {
		case 1: {
			decoding();
			break;
		}
		case 0: {
			return 0;
			break;
		}
		default: {

			cout << "\nТакой операции нет.\n\n";
			break;

		}
		}
	}

}