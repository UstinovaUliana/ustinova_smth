﻿#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm> 
#include <string>
using namespace std;

vector<pair<char, int>> freq(vector<char> text) {
	multimap<char, int> lettersCodes;
	multimap<char, int> ::iterator it;
	map<char, int> lettersFreqs;
	int freqency;
	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = 0; i <= 255; i++) {
		freqency = lettersCodes.count(i);
		if (freq != 0)
			lettersFreqs.insert(pair<char, int>(i, freqency));
	}
	auto comp = [](const pair<char, int>& p1, const pair<char, int>& p2) {
		return p1.second > p2.second;
	};

	vector<pair<char, int>> sorted;

	for (auto it = lettersFreqs.begin(); it != lettersFreqs.end(); it++) {
		sorted.push_back(make_pair(it->first, it->second));
	};
	
	sort(sorted.begin(), sorted.end(), comp);	
	return sorted;
}
float index_sootv(vector<char> text) {
	multimap<char, int> lettersCodes;
	multimap<char, int> ::iterator it;
	map<char, int> lettersFreqs;
	int freqency;
	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = 0; i <= 255; i++) {
		freqency = lettersCodes.count(i);
		if (freqency != 0)
			lettersFreqs.insert(pair<char, int>(i, freqency));
	}

	float indexS=0;
	int N = text.size();
	for (auto fi : lettersFreqs) indexS += fi.second * (fi.second - 1);
		
	return indexS/(N * (N - 1));
}
void etalon_analysis() {
	string etFileName;
	std::cout << "Введите название файла с эталонным текстом: ";
	std::cin >> etFileName;
	ifstream fin(etFileName, ios::binary);
	vector<char> etText((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>()); //эталонный текст
	fin.close();

	vector<pair<char, int>>  lettersFreqs;
	vector<pair<char, int>> ::iterator it;
	lettersFreqs=freq(etText);
	int i = 1;
	for (it=lettersFreqs.begin(); i < 6; i++, it++) 	std::cout << "\nСимвол: \'" << it->first << "\'; Частота: " << (double)it->second/etText.size();
	float is=index_sootv(etText);
	std::cout << "\nИндекс соответствия: " << is << "\n";
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
	char decoded_letter;
	std::cout << "Введите название файла с зашифрованным текстом: ";
	std::cin >> codedFileName;
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
		std::cout << "\nДлина ключа: " << keySize << "; Индекс соответствия: " << isi;
		
		if ((keySize > 1) && (is.at(keySize - 1) > is.at(keySize - 2)*2) &&(expKeySize==1)) {
			maxIndex = isi;
			expKeySize = keySize;
		}
		group.clear();
	}
	cout << "\nПредполагаемая длина ключа: " << expKeySize <<"\n";
	

	vector<pair<char, int>>  groupFreqs;
	int trueKeySize;
	vector<char>keyword;
	std::cout << "Введите истиную длину ключа: ";
	std::cin >> trueKeySize;
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
	std::cout << "Ключ: ";
	for (auto i : keyword) 	std::cout << i;
	std::cout << "\nВведите название файла, куда сохранить расшифрованный текст: ";
	std::cin >> outFileName;
	int letterPos = 0;
	ofstream fout(outFileName, ios::binary);
	for (auto codedLetter : codedText) {
		decoded_letter = codedLetter - char(keyword[letterPos % trueKeySize]);
		fout << decoded_letter;
		letterPos++;
	}
	fout.close();
	std::cout << "\nСохранено!\n";
}

int main()
{

	setlocale(LC_ALL, "Russian");
	
	while (true) {
		std::cout << "1. Анализ эталонного текста\n2. Анализ зашифрованного текста и дешифровка\n";
		std::cout << "0. Выход из программы\n";
		int com;
		std::cin >> com;
		switch (com) {
		case 1: {
			etalon_analysis();
			break;
		}
		case 2: {
			decoding();
			break;
		}
		case 0: {
			return 0;
			break;
		}
		default: {
			std::cout << "\nТакой операции нет.\n\n";
			break;
		}
		}
	}
}