#pragma once
#include "pch.h"

class ustinova_tea : public CObject {
public:
	DECLARE_SERIAL(ustinova_tea);
	CString name, sort;
	int price, rate;
	ustinova_tea();
	virtual  ~ustinova_tea();
	CString text;
	CSize extent;
	virtual void Serialize(CArchive& archive);
	virtual CString UpdateText();
	void Draw(CDC* tDC, CSize& size);
	void CalcScrollSizes(CSize& size);
};

