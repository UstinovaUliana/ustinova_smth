#include "pch.h"
#include "ustinova_favouriteTea.h"

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