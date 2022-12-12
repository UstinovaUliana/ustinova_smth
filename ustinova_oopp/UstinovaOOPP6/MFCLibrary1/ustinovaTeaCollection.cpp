#include "pch.h"
#include "ustinovaTeaCollection.h"
#include "ustinovaTea.h"
#include "ustinovaFavouriteTea.h"

IMPLEMENT_SERIAL(ustinovaTeaCollection, CDocument, 0);

ustinovaTeaCollection::ustinovaTeaCollection()
{
}

ustinovaTeaCollection::~ustinovaTeaCollection()
{

}

void ustinovaTeaCollection::PrintF(const char* szPath)
{
	CFile out(CString(szPath), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&out, CArchive::store);

	ar << ukazateli.size();
	for (auto ukaz : ukazateli)  ar << ukaz.get();
	ar.Close();
}

void ustinovaTeaCollection::AddF(const char* szPath)
{
	ukazateli.clear();
	CFile in(CString(szPath), CFile::modeRead);
	CArchive ar(&in, CArchive::load);

	int size;
	ar >> size;
	for (int i = 0; i < size; i++) {
		ustinovaTea* p_cur = new ustinovaTea;
		ar >> p_cur;
		shared_ptr<ustinovaTea> cur(p_cur);
		ukazateli.push_back(cur);
	}
	ar.Close();
	in.Close();
}

void ustinovaTeaCollection::clearList()
{
	ukazateli.clear();
}
