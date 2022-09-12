#pragma once
#include "ustinova_tea.h"
#include "ustinova_favouriteTea.h"
#include <vector>

class ustinova_teaCollection
{
public:
	vector <shared_ptr<ustinova_tea>> ukazateli;
	vector<shared_ptr<ustinova_tea>>::iterator it;
	ustinova_teaCollection();
	~ustinova_teaCollection();
	void c_out();
	void f_in();
	void f_out();
	void clear();
	void add_tea(bool is_favourite);
	//friend std::ostream& operator<< (std::ostream& out, const ustinova_teaCollection& collection);
	////friend std::istream& operator>> (std::istream& in, ustinova_teaCollection& collection);
	//friend std::ifstream& operator>> (std::ifstream& fin, ustinova_teaCollection& collection);
	//friend std::ofstream& operator<< (std::ofstream& fout, ustinova_teaCollection& collection);

};

