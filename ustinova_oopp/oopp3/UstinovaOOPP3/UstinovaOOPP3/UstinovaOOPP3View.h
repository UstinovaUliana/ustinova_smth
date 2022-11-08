
// UstinovaOOPP3View.h: интерфейс класса CUstinovaOOPP3View
//

#pragma once


class CUstinovaOOPP3View : public CScrollView
{
protected: // создать только из сериализации
	CUstinovaOOPP3View() noexcept;
	DECLARE_DYNCREATE(CUstinovaOOPP3View)

// Атрибуты
public:
	CUstinovaOOPP3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CUstinovaOOPP3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в UstinovaOOPP3View.cpp
inline CUstinovaOOPP3Doc* CUstinovaOOPP3View::GetDocument() const
   { return reinterpret_cast<CUstinovaOOPP3Doc*>(m_pDocument); }
#endif

