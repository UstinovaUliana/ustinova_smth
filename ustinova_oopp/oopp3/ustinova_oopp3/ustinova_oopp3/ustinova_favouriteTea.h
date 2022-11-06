#pragma once
#include "ustinova_tea.h"
#include "pch.h"

class ustinova_favouriteTea : public ustinova_tea
{
public:
	DECLARE_SERIAL(ustinova_favouriteTea);
	int personal_rate;
	ustinova_favouriteTea();
	~ustinova_favouriteTea();
	virtual void Serialize(CArchive& archive);
	virtual CString UpdateText();
};

