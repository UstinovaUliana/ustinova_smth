#pragma once
#include "pch.h"
#include "ustinova_tea.h"
#include "ustinova_favouriteTea.h"

class ustinova_teaCollection
{
public:
	vector <shared_ptr<ustinova_tea>> ukazateli;
	ustinova_teaCollection();
	void ViewWrite(CDC* pDC, int& h, int& w);
	void LoadFromFile(CArchive& ar);
	void SaveToFile(CArchive& ar);
};

