#pragma once
#include <string>
#include <fstream>
#include <iostream>
class ustinova_tea
{public:
	std::string name, country_from, company, sort;
	int price, rate;
	ustinova_tea();
	~ustinova_tea();
	void c_in();
	void c_out();
	void f_in(std::ifstream& fin);
	void f_out(std::ofstream& fout);
	//friend std::ostream& operator<< (std::ostream& out, const ustinova_tea& tea);
	//friend std::istream& operator>> (std::istream& in, ustinova_tea& tea);
	//friend std::ifstream& operator>> (std::ifstream& fin, ustinova_tea& tea);
	//friend std::ofstream& operator<< (std::ofstream& out, ustinova_tea& tea);
};

