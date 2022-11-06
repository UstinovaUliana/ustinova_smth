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
CString ustinova_favouriteTea::UpdateText()
{
	CString outPrice, outRate, outPerRate;
	outPrice.Format(L"%f", price);
	outRate.Format(L"%f", rate);
	outPerRate.Format(L"%f", personal_rate);
	CString utext = name + " " + sort + " " + outPrice + " " + outRate+ " " + outPerRate;
	return utext;
}