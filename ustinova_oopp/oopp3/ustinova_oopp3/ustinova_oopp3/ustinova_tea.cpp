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
	CString utext = name + " " + sort + " " + to_string(price).c_str() + " " + to_string(rate).c_str() ;
	return utext;
}

void ustinova_tea::Draw(CDC* pDC, CSize& size)
{
	text = UpdateText();

	pDC->TextOut(size.cx, size.cy, text);

	extent = pDC->GetTextExtent(text);
	size.cy += extent.cy;
}

void ustinova_tea::CalcScrollSizes(CSize& size)
{
	size.cx = max(size.cx, extent.cx);
	size.cy += extent.cy;
}