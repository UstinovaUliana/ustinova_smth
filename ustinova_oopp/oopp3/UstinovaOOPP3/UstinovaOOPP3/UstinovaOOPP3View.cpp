
// UstinovaOOPP3View.cpp: реализация класса CUstinovaOOPP3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "UstinovaOOPP3.h"
#endif

#include "UstinovaOOPP3Doc.h"
#include "UstinovaOOPP3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUstinovaOOPP3View

IMPLEMENT_DYNCREATE(CUstinovaOOPP3View, CScrollView)

BEGIN_MESSAGE_MAP(CUstinovaOOPP3View, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение CUstinovaOOPP3View

CUstinovaOOPP3View::CUstinovaOOPP3View() noexcept
{
	// TODO: добавьте код создания

}

CUstinovaOOPP3View::~CUstinovaOOPP3View()
{
}

BOOL CUstinovaOOPP3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CUstinovaOOPP3View

void CUstinovaOOPP3View::OnDraw(CDC* pDC)
{
	CUstinovaOOPP3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	int h = 0;
	int w = 0;
	pDoc->collection.ViewWrite(pDC, h, w);

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	CSize sizeTotal;
	sizeTotal.cx = w * tm.tmAveCharWidth;
	sizeTotal.cy = h;
	SetScrollSizes(MM_TEXT, sizeTotal);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}

void CUstinovaOOPP3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CUstinovaOOPP3View

#ifdef _DEBUG
void CUstinovaOOPP3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CUstinovaOOPP3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CUstinovaOOPP3Doc* CUstinovaOOPP3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUstinovaOOPP3Doc)));
	return (CUstinovaOOPP3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CUstinovaOOPP3View
