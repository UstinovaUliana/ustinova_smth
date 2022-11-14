#include "pch.h"
#include "ustinova_favouriteTea.h"

#include "ustinova_editDialog.h"
ustinova_favouriteTea::ustinova_favouriteTea()
{
};
ustinova_favouriteTea::~ustinova_favouriteTea()
{
};

IMPLEMENT_SERIAL(ustinova_favouriteTea, ustinova_tea, 1);

void ustinova_favouriteTea::Serialize(CArchive& arch) {
	ustinova_tea::Serialize(arch);
	if (arch.IsStoring()) {
		arch << personal_rate;
	}
	else {
		arch >> personal_rate;
	}
}
//CString ustinova_favouriteTea::UpdateText()
//{
//	CString utext = name + " " + sort + " " + to_string(price).c_str() + " " + to_string(rate).c_str() + " " + to_string(personal_rate).c_str();
//	return utext;
//}
void  ustinova_favouriteTea::ViewWrite(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Любимый чай");
	pDC->TextOut(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext = _T("Название: ") + name + _T(";   Сорт: ") + sort + _T(";   Цена: ") + to_string(price).c_str() + _T(";   Оценка: ") + to_string(rate).c_str()
		+ _T(";   Ваша оценка: ") + to_string(personal_rate).c_str();
	pDC->TextOut(0, h, utext);
	if (utext.GetLength() > w)
		w = utext.GetLength();
	h += 40;
	//int pr = personal_rate;
	//+ to_string(pr).c_str();
	/*CString utext2 = _T("   Ваша оценка: ") + to_string(price).c_str();
	pDC->TextOut(0, h, utext2);
	if (utext2.GetLength() > w)
		w = utext2.GetLength();
	h += 40;*/
}
void ustinova_favouriteTea::outputTea(ustinova_editDialog* dlg)
{
	dlg->NameText = this->name;
	dlg->SortText = this->sort;
	dlg->PriceText = to_string(this->price).c_str();
	dlg->RateText = to_string(this->rate).c_str();
	dlg->PerRateText = to_string(this->personal_rate).c_str();

	dlg->PerRateEdit.ShowWindow(SW_SHOW);
	dlg->PerRateLabel.ShowWindow(SW_SHOW);
}

void ustinova_favouriteTea::inputTea(ustinova_editDialog* dlg)
{
	name = dlg->NameText;
	sort = dlg->SortText;
	price = _ttoi(dlg->PriceText);
	rate = _ttoi(dlg->RateText);
	personal_rate = _ttoi(dlg->PerRateText);;
}

CString ustinova_favouriteTea::getName() const
{
	return name;
}