
// UstinovaOOPP3Doc.cpp: реализация класса CUstinovaOOPP3Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "UstinovaOOPP3.h"
#endif

#include "UstinovaOOPP3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CUstinovaOOPP3Doc

IMPLEMENT_DYNCREATE(CUstinovaOOPP3Doc, CDocument)

BEGIN_MESSAGE_MAP(CUstinovaOOPP3Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CUstinovaOOPP3Doc

CUstinovaOOPP3Doc::CUstinovaOOPP3Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CUstinovaOOPP3Doc::~CUstinovaOOPP3Doc()
{
}

BOOL CUstinovaOOPP3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CUstinovaOOPP3Doc

void CUstinovaOOPP3Doc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		collection.SaveToFile(ar);
	}
	else
	{
		// TODO: добавьте код загрузки
		collection.LoadFromFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CUstinovaOOPP3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CUstinovaOOPP3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CUstinovaOOPP3Doc::SetSearchContent(const CString& value)
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

// Диагностика CUstinovaOOPP3Doc

#ifdef _DEBUG
void CUstinovaOOPP3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUstinovaOOPP3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

//
//// Команды CUstinovaOOPP3Doc
//void CUstinovaOOPP3Doc::Draw(CDC* pDC)
//{
//	CSize size(0, 0);
//	for_each(ukazateli.begin(), ukazateli.end(), bind(&ustinova_tea::Draw, placeholders::_1, pDC, ref(size)));
//}
//
//CSize CUstinovaOOPP3Doc::GetScrollSizes()
//{
//	CSize result;
//	for_each(ukazateli.begin(), ukazateli.end(), bind(&ustinova_tea::CalcScrollSizes, placeholders::_1, ref(result)));
//	return result;
//}