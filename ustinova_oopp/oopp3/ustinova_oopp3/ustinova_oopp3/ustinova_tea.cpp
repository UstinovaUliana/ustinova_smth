#include "pch.h"
#include "ustinova_tea.h"
ustinova_tea::ustinova_tea()
{
}

ustinova_tea::~ustinova_tea()
{
}

IMPLEMENT_SERIAL(ustinova_tea, CObject, 1)

void ustinova_tea::Serialize(CArchive& file) {
	if (file.IsStoring()) {
		file << name  << sort << price << rate;
	}
	else {
		file >> name >> sort >> price >> rate;
	}
}

CString ustinova_tea::UpdateText()
{
	CString outPrice, outRate;
	outPrice.Format(L"%f", price);
	outRate.Format(L"%f", rate);
	CString utext = name + " "+ sort + " " + outPrice + " " + outRate;
	return utext;
}

void ustinova_tea::Draw(CDC* tDC, CSize& size)
{
	text = UpdateText();

	tDC->TextOut(size.cx, size.cy, text);

	extent = tDC->GetTextExtent(text);
	size.cy += extent.cy;
}

void ustinova_tea::CalcScrollSizes(CSize& size)
{
	size.cx = max(size.cx, extent.cx);
	size.cy += extent.cy;
}