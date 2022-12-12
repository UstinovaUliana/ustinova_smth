#pragma once
#include "pch.h"
#include "ustinovaTea.h"

class ustinovaTeaCollection:public CObject
{
	public:
		DECLARE_SERIAL(ustinovaTeaCollection);

		vector<shared_ptr<ustinovaTea>> ukazateli;

		ustinovaTeaCollection();
		~ustinovaTeaCollection();

		void PrintF(const char* szPath);
		void AddF(const char* szPath);

		void clearList();
};

