#include "pch.h"
#include "ustinova_tea.h"
#include "ustinova_editDialog.h"
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

void ustinova_tea::outputTea(ustinova_editDialog* dlg)
{
	dlg->NameText = this->name;
	dlg->SortText = this->sort;
	dlg->PriceText = to_string(this->price).c_str();
	dlg->RateText = to_string(this->rate).c_str();
	dlg->PerRateText = "";
	dlg->PerRateEdit.ShowWindow(SW_HIDE);
	dlg->PerRateLabel.ShowWindow(SW_HIDE);
}

void ustinova_tea::inputTea(ustinova_editDialog* dlg)
{
	name = dlg->NameText;
	sort = dlg->SortText;
	price = _ttoi(dlg->PriceText);
	rate = _ttoi(dlg->RateText);
}

CString ustinova_tea::getName() const
{
	return name;
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

