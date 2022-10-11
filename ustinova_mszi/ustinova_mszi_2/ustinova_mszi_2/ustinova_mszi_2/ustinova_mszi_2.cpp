#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm> 
#include <set>
#include <string>
using namespace std;

vector<pair<char, int>> freq(vector<char> text) {
	multimap<char, int> lettersCodes;
	multimap<char, int> ::iterator it;
	map<char, int> lettersFreqs;
	int freq;
	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = 0; i <= 255; i++) {
		freq = lettersCodes.count(i);
		if (freq != 0)
			lettersFreqs.insert(pair<char, int>(i, freq));
	}
	auto comp = [](const pair<char, int>& p1, const pair<char, int>& p2) {
		return p1.second > p2.second;
	};
	vector <int> f;
	multimap<int, char>sorted;
	unordered_map <char, int> lettersFreqs1;
	/*sort(lettersFreqs.begin(), lettersFreqs.end(), comp);*/
	//for (auto i : lettersFreqs) f.push_back(i.second);
	for (auto i : lettersFreqs) sorted.emplace(i.second, i.first);

	//sort(f.begin(), f.end());
	//for (auto i:sorted) lettersFreqs1.emplace(i.second, i.first);
	auto start = 0;
	vector<pair<char, int>> aw;
	for (auto it=sorted.rbegin(); it!= sorted.rend(); it++) {
		lettersFreqs1.emplace(it->second, it->first);
		start++;
		aw.push_back(make_pair(it->second, it->first));
		if (start==5) return aw;
	}
	
	
}
float index_sootv(vector<char> text) {
	multimap<char, int> lettersCodes;
	multimap<char, int> ::iterator it;
	map<char, int> lettersFreqs;
	int freq;
	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = 0; i <= 255; i++) {
		freq = lettersCodes.count(i);
		if (freq != 0)
			lettersFreqs.insert(pair<char, int>(i, freq));
	}

	float index=0;
	int N = text.size();
	for (auto fi : lettersFreqs) index += fi.second * (fi.second - 1);
		
	return index/(N * (N - 1));
}
void etalon_analysis() {
	string etFileName;
	cout << "Введите название файла с эталонным текстом: \n";
	cin >> etFileName;
	ifstream fin(etFileName, ios::binary);
	vector<char> etText((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>()); //эталонный текст
	fin.close();

	vector<pair<char, int>>  lettersFreqs;
	unordered_map<char, int> ::iterator it;
	lettersFreqs=freq(etText);
	int i = 1;
	for (auto it: lettersFreqs) cout << "Символ: " << it.first << "; Частота: " << it.second << "\n";
	float is=index_sootv(etText);
	cout << "Индекс соответствия: " << is << "\n";
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
	
	
}
void decoding() {
	int keySize;
	string codedFileName, outFileName;
	//
	char decoded_letter;
	//map<char, float> codedChastoty; //анализ группы зашифрованного текста
	//vector<char> sym_in_groups; //символы в группах
	//vector<int> keyword; //смещение

	cout << "Введите название файла с зашифрованным текстом\n";
	cin >> codedFileName;
	ifstream fin1(codedFileName, ios::binary);
	vector<char> codedText((istreambuf_iterator<char>(fin1)), istreambuf_iterator<char>()); //зашифрованный текст
	fin1.close();

	vector <char> group;
	float maxIndex = 0;
	int expKeySize=1;
	vector<float> is;
	for (int keySize = 1; keySize <= 25; keySize++) {
		for (int j = 0; j < codedText.size(); j+=keySize)
		{
			group.push_back(codedText.at(j));
		}
		float isi = index_sootv(group);
		is.push_back(isi);
		cout << "Длина ключа: " << keySize << "; Индекс соответствия: " << isi << "\n";
		
			maxIndex = isi;
			expKeySize = keySize;
			
		group.clear();
	}
	//cout << "Предполагаемая длина ключа: " << expKeySize <<"\n";
	

	vector<pair<char, int>>  groupFreqs;
	int trueKeySize;
	vector<char>keyword;
	cout << "Введите истиную длину ключа: ";
	cin >> trueKeySize;
	for (int i = 0; i < trueKeySize;i++) {
		for (int j = i; j < codedText.size(); j += trueKeySize)
		{
			group.push_back(codedText.at(j));
		}
		groupFreqs = freq(group);
		auto s =groupFreqs.begin();
		const char p = ' ';
		keyword.push_back(char(s->first - p));
		group.clear();
		groupFreqs.clear();
	}
	cout << "Ключ: ";
	for (auto i : keyword) cout << i;
	cout << "\n";
	/*action = 2;
	coding(action);*/
	cout << "Введите название файла, куда сохранить расшифрованный текст: \n";
	cin >> outFileName;
	int letterPos = 0;
	ofstream fout(outFileName, ios::binary);
	for (auto codedLetter : codedText) {
		decoded_letter = codedLetter - char(keyword[letterPos % trueKeySize]);
		fout << decoded_letter;
		letterPos++;
	}
	fout.close();
	cout << "\nСохранено!\n";
}
void coding(int action) {
	std::ifstream fin;
	std::ofstream fout;
	string keyword;
	string output_file, input_file;
	char letter, coded_letter;
	cout << "\nВведите название файла с исходным текстом: ";
	cin >> ws;
	getline(cin, input_file);
	
	cout << "\nВведите название файла, куда будет сохранён текст: ";
	cin >> ws;
	getline(cin, output_file);

	cout << "Введите ключевое слово:";
	cin >> ws;
	getline(cin, keyword);

	fin.open(input_file, ios::binary);
	fout.open(output_file, ios::binary);

	int keyword_letter_code = 0;
	if (!fin.is_open())
		cout << "Невозможно открыть файл.\n";
	else
		while (fin.get(letter)) {

			if (action== 1) {
				coded_letter = letter + keyword_letter_code;
				fout << coded_letter;
			}
			else {
				coded_letter = letter - keyword_letter_code;
				fout << coded_letter;
			}
			keyword_letter_code++;
			if (keyword_letter_code > keyword.size()) keyword_letter_code = 0;
		}
	fin.close();
	fout.close();

}
int main()
{

	setlocale(LC_ALL, "Russian");
	
	while (true) {
		cout << "1. Анализ эталонного текста\n2. Анализ зашифрованного текста и дешифровка\n 3.  Зашифровать текст";
		cout << "0. Выход из программы\n";
		int com;
		int action;
		cin >> com;
		switch (com) {
		case 1: {
			etalon_analysis();
			
			break;
		}
		case 2: {
			decoding();
			
			break;
		}
		case 3: {
			action = 1;
			coding(action);
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