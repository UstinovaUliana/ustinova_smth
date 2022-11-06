
// ustinova_oopp3View.h: интерфейс класса Custinovaoopp3View
//

#pragma once


class Custinovaoopp3View : public CScrollView
{
protected: // создать только из сериализации
	Custinovaoopp3View() noexcept;
	DECLARE_DYNCREATE(Custinovaoopp3View)

// Атрибуты
public:
	Custinovaoopp3Doc* GetDocument() const;

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
	virtual ~Custinovaoopp3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в ustinova_oopp3View.cpp
inline Custinovaoopp3Doc* Custinovaoopp3View::GetDocument() const
   { return reinterpret_cast<Custinovaoopp3Doc*>(m_pDocument); }
#endif

