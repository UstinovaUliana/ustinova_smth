
// UstinovaOOPP3Doc.h: интерфейс класса CUstinovaOOPP3Doc 
//


#pragma once
#include "ustinova_teaCollection.h"

class CUstinovaOOPP3Doc : public CDocument
{
protected: // создать только из сериализации
	CUstinovaOOPP3Doc() noexcept;
	DECLARE_DYNCREATE(CUstinovaOOPP3Doc)

// Атрибуты
public:
	ustinova_teaCollection collection;
	//vector <shared_ptr<ustinova_tea>> ukazateli;
// Операции
public:
	/*void Draw(CDC* pDC);
	CSize GetScrollSizes();*/
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CUstinovaOOPP3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
