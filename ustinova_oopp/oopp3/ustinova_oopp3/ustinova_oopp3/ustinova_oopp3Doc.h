
// ustinova_oopp3Doc.h: интерфейс класса Custinovaoopp3Doc 
//


#pragma once
#include "ustinova_tea.h"

class Custinovaoopp3Doc : public CDocument
{
protected: // создать только из сериализации
	Custinovaoopp3Doc() noexcept;
	DECLARE_DYNCREATE(Custinovaoopp3Doc)

// Атрибуты
public:
	vector <shared_ptr<ustinova_tea>> ukazateli;
// Операции
public:
	void Draw(CDC* pDC);
	CSize GetScrollSizes();
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
	virtual ~Custinovaoopp3Doc();
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
