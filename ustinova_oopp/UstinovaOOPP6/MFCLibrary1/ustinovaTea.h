#pragma once
#include "pch.h"

class ustinovaTea: public CObject
{
	public:
		DECLARE_SERIAL(ustinovaTea);
		CString name="null";
		CString sort="null" ;
		int price = 0;
		int rate = 0;

		ustinovaTea();
		~ustinovaTea();
		virtual void Serialize(CArchive& ar);
};

