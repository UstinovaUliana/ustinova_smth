#include "pch.h"
#include "ustinovaTea.h"

IMPLEMENT_SERIAL(ustinovaTea, CObject, 0);

ustinovaTea::ustinovaTea()
{
}

ustinovaTea::~ustinovaTea()
{

}

void ustinovaTea::Serialize(CArchive& ar) {

	if (ar.IsStoring())
	{
		ar << name;
		ar << sort;
		ar << price;
		ar << rate;
	}
	else
	{
		ar >> name;
		ar >> sort;
		ar >> price;
		ar >> rate;
	}
}