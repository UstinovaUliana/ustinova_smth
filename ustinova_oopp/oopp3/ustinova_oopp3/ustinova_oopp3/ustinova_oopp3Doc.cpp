
// ustinova_oopp3Doc.cpp: реализация класса Custinovaoopp3Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ustinova_oopp3.h"
#endif

#include "ustinova_oopp3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Custinovaoopp3Doc

IMPLEMENT_DYNCREATE(Custinovaoopp3Doc, CDocument)

BEGIN_MESSAGE_MAP(Custinovaoopp3Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение Custinovaoopp3Doc

Custinovaoopp3Doc::Custinovaoopp3Doc() noexcept
{
}

Custinovaoopp3Doc::~Custinovaoopp3Doc()
{
}

BOOL Custinovaoopp3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}


// Сериализация Custinovaoopp3Doc

void Custinovaoopp3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << ukazateli.size();

		for_each(ukazateli.begin(), ukazateli.end(), [&](shared_ptr<ustinova_tea> tea) { ar << tea.get(); });
	}
	else
	{
		size_t ukaz_size;
		int n;
		ar >> ukaz_size;
		ar >> n;
		for (size_t i = 0; i < ukaz_size; i++)
		{
			ustinova_tea* tea;
			ar >> tea;
			ukazateli.push_back(shared_ptr<ustinova_tea>(tea));
		}
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void Custinovaoopp3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void Custinovaoopp3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void Custinovaoopp3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика Custinovaoopp3Doc

#ifdef _DEBUG
void Custinovaoopp3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Custinovaoopp3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды Custinovaoopp3Doc
void Custinovaoopp3Doc::Draw(CDC* pDC)
{
	CSize size(0, 0);
	for_each(ukazateli.begin(), ukazateli.end(), bind(&ustinova_tea::Draw, placeholders::_1, pDC, ref(size)));
}

CSize Custinovaoopp3Doc::GetScrollSizes()
{
	CSize result;
	for_each(ukazateli.begin(), ukazateli.end(), bind(&ustinova_tea::CalcScrollSizes, placeholders::_1, ref(result)));
	return result;
}
