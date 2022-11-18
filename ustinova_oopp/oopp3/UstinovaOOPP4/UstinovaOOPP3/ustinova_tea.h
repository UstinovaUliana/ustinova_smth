#pragma once
#include "pch.h"
class ustinova_editDialog;

class ustinova_tea : public CObject {
public:
	DECLARE_SERIAL(ustinova_tea);
	CString name, sort;
	int price, rate;
	ustinova_tea();
	virtual  ~ustinova_tea();
	virtual void Serialize(CArchive& archive);
	virtual void ViewWrite(CDC* pDC, int& h, int& w);
	virtual void inputTea(ustinova_editDialog* dlg);
	virtual void outputTea(ustinova_editDialog* dlg);
	CString getName() const;
	/*virtual CString UpdateText();
	void Draw(CDC* tDC, CSize& size);
	void CalcScrollSizes(CSize& size);*/
};

