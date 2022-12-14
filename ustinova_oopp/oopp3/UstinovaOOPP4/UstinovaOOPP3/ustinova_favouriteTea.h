#pragma once
#include "ustinova_tea.h"
#include "pch.h"

class ustinova_favouriteTea : public ustinova_tea
{
public:
	DECLARE_SERIAL(ustinova_favouriteTea);
	int personal_rate;
	ustinova_favouriteTea();
	virtual ~ustinova_favouriteTea();
	void ViewWrite(CDC* pDC, int& h, int& w);
	virtual void Serialize(CArchive& archive);

	virtual void inputTea(ustinova_editDialog* dlg);
	virtual void outputTea(ustinova_editDialog* dlg);
	CString  getName() const;
	/*virtual CString UpdateText();*/
};

