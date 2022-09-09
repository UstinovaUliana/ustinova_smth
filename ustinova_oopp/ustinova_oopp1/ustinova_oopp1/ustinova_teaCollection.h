#pragma once
#include "ustinova_tea.h"
#include <vector>
class ustinova_teaCollection
{
public:
	std::vector <ustinova_tea*> ukazateli;
	void add_tea();
	ustinova_teaCollection();
	~ustinova_teaCollection();
	void c_out();
	void f_in(std::ifstream& fin);
	void f_out(std::ofstream& fout);
	//friend std::ostream& operator<< (std::ostream& out, const ustinova_teaCollection& collection);
	////friend std::istream& operator>> (std::istream& in, ustinova_teaCollection& collection);
	//friend std::ifstream& operator>> (std::ifstream& fin, ustinova_teaCollection& collection);
	//friend std::ofstream& operator<< (std::ofstream& fout, ustinova_teaCollection& collection);
	void clear();
};

