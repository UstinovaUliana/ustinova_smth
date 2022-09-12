#pragma once
#include "ustinova_tea.h"
class ustinova_favouriteTea : public ustinova_tea
{
public:
	DECLARE_SERIAL(ustinova_favouriteTea);
	int personal_rate;
	ustinova_favouriteTea();
	~ustinova_favouriteTea();
	virtual void c_in();
	virtual void c_out();
	virtual void Serialize(CArchive& archive);

};

