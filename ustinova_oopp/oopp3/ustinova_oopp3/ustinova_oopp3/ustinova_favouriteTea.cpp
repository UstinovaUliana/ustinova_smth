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
	CString utext = name + " " + sort + " " + to_string(price).c_str() + " " + to_string(rate).c_str() + " " + to_string(personal_rate).c_str();
	return utext;
}