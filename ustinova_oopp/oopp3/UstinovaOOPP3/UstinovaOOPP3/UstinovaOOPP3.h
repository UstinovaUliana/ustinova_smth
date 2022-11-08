
// UstinovaOOPP3.h: основной файл заголовка для приложения UstinovaOOPP3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CUstinovaOOPP3App:
// Сведения о реализации этого класса: UstinovaOOPP3.cpp
//

class CUstinovaOOPP3App : public CWinApp
{
public:
	CUstinovaOOPP3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUstinovaOOPP3App theApp;
