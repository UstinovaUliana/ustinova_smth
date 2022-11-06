
// ustinova_oopp3View.cpp: реализация класса Custinovaoopp3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "ustinova_oopp3.h"
#endif

#include "ustinova_oopp3Doc.h"
#include "ustinova_oopp3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Custinovaoopp3View

IMPLEMENT_DYNCREATE(Custinovaoopp3View, CScrollView)

BEGIN_MESSAGE_MAP(Custinovaoopp3View, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение Custinovaoopp3View

Custinovaoopp3View::Custinovaoopp3View() noexcept
{

}

Custinovaoopp3View::~Custinovaoopp3View()
{
}

BOOL Custinovaoopp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

// Рисование Custinovaoopp3View

void Custinovaoopp3View::OnDraw(CDC* pDC)
{
	Custinovaoopp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Draw(pDC);
	SetScrollSizes(MM_TEXT, pDoc->GetScrollSizes());
}

void Custinovaoopp3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика Custinovaoopp3View

#ifdef _DEBUG
void Custinovaoopp3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Custinovaoopp3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Custinovaoopp3Doc* Custinovaoopp3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Custinovaoopp3Doc)));
	return (Custinovaoopp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений Custinovaoopp3View
