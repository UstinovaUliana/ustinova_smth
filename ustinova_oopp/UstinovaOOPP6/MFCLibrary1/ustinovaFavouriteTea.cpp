#include "pch.h"
#include "ustinovaFavouriteTea.h"

IMPLEMENT_SERIAL(ustinovaFavouriteTea, ustinovaTea, 0);

ustinovaFavouriteTea::ustinovaFavouriteTea() {

}

ustinovaFavouriteTea::~ustinovaFavouriteTea() {

}

void ustinovaFavouriteTea::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) {
		ustinovaTea::Serialize(ar);
		ar << personal_rate;
	}
	else {
		ustinovaTea::Serialize(ar);
		ar >> personal_rate;
	}
}