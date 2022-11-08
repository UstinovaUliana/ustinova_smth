#include "pch.h"
#include "ustinova_tea.h"
ustinova_tea::ustinova_tea()
{
}

ustinova_tea::~ustinova_tea()
{
}

IMPLEMENT_SERIAL(ustinova_tea, CObject, 1)

void ustinova_tea::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	if (archive.IsStoring()) {
		archive << name << sort << price << rate;
	}
	else {
		archive >> name >> sort >> price >> rate;
	}
}

void ustinova_tea::ViewWrite(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Чай");
	pDC->TextOut(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext = _T("Название: ") + name + _T(";   Сорт: ") + sort + _T(";   Цена: ") + to_string(price).c_str() + _T(";   Оценка: ") + to_string(rate).c_str();
	pDC->TextOut(0, h, utext);
	if (utext.GetLength() > w)
		w = utext.GetLength();
	h += 40;
}

//CString ustinova_tea::UpdateText()
//{
//	CString utext = name + " " + sort + " " + to_string(price).c_str() + " " + to_string(rate).c_str();
//	return utext;
//}
//
//void ustinova_tea::Draw(CDC* pDC, CSize& size)
//{
//	text = UpdateText();
//
//	pDC->TextOut(size.cx, size.cy, text);
//
//	extent = pDC->GetTextExtent(text);
//	size.cy += extent.cy;
//}
//
//void ustinova_tea::CalcScrollSizes(CSize& size)
//{
//	size.cx = max(size.cx, extent.cx);
//	size.cy += extent.cy;
//}

