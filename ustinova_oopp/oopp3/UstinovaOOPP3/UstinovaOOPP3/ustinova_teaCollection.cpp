#include "pch.h"
#include "ustinova_teaCollection.h"
void ustinova_teaCollection::ViewWrite(CDC* pDC, int& h, int& w)
{
    CString str1 = _T("Чайная коллекция:");
    w = str1.GetLength();
    pDC->TextOut(0, h, str1);
    h += 40;
    if (ukazateli.empty())
    {
        pDC->TextOut(0, h, _T("Коллекция пуста\n"));
        if (string("Коллекция пуста").length() > w)
            w = str1.GetLength();
    }
    else
        for_each(ukazateli.begin(), ukazateli.end(), bind(&ustinova_tea::ViewWrite, placeholders::_1, pDC, ref(h), ref(w)));
}

void ustinova_teaCollection::LoadFromFile(CArchive& ar)
{
    int collSize,n;
    ar >> collSize;
    ar >> n;
    ukazateli.clear();
    ukazateli.reserve(collSize);
    for (int i = 0; i < collSize; i++)
    {
        ustinova_tea* ukaz;
        ar >> ukaz;
        ukazateli.push_back(shared_ptr<ustinova_tea>(ukaz));
    }
}

void ArchiveTea(CArchive& archive, shared_ptr<ustinova_tea> tea)
{
    archive << tea.get();
}

void ustinova_teaCollection::SaveToFile(CArchive& ar)
{
    ar << ukazateli.size();
    for_each(ukazateli.begin(), ukazateli.end(), bind(ArchiveTea, ref(ar), placeholders::_1));
}

ustinova_teaCollection::ustinova_teaCollection()
{
  
}

