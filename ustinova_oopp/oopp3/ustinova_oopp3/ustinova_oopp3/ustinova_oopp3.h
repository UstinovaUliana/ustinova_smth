
// ustinova_oopp3.h: основной файл заголовка для приложения ustinova_oopp3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Custinovaoopp3App:
// Сведения о реализации этого класса: ustinova_oopp3.cpp
//

class Custinovaoopp3App : public CWinApp
{
public:
	Custinovaoopp3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Custinovaoopp3App theApp;
