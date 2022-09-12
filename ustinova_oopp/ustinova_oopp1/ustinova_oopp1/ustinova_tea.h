#pragma once
#include "Header.h"

class ustinova_tea : public CObject
{public:
	DECLARE_SERIAL(ustinova_tea);
	CString name, country_from, company, sort;
	int price, rate;
	ustinova_tea();
	~ustinova_tea();
	virtual void c_in();
	virtual void c_out();
	virtual void Serialize(CArchive& archive);

	/*void f_in(std::ifstream& fin);
	void f_out(std::ofstream& fout);*/

	//friend std::ostream& operator<< (std::ostream& out, const ustinova_tea& tea);
	//friend std::istream& operator>> (std::istream& in, ustinova_tea& tea);
	//friend std::ifstream& operator>> (std::ifstream& fin, ustinova_tea& tea);
	//friend std::ofstream& operator<< (std::ofstream& out, ustinova_tea& tea);
};

