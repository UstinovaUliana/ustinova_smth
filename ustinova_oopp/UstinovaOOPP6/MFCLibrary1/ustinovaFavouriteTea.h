#pragma once
#include "pch.h"
#include "ustinovaTea.h"

class ustinovaFavouriteTea : public ustinovaTea
{
	public:
		DECLARE_SERIAL(ustinovaFavouriteTea);

		int personal_rate = 0;

		ustinovaFavouriteTea();
		~ustinovaFavouriteTea();

		void Serialize(CArchive& ar);
};

