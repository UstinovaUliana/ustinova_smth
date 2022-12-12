// MFCLibrary1.cpp: определяет процедуры инициализации для библиотеки DLL.
//
#include "pch.h"
#include "framework.h"
#include "MFCLibrary1.h"
#include "ustinovaTeaCollection.h"
#include "ustinovaTea.h"
#include "ustinovaFavouriteTea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibrary1App

BEGIN_MESSAGE_MAP(CMFCLibrary1App, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibrary1App

CMFCLibrary1App::CMFCLibrary1App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibrary1App

CMFCLibrary1App theApp;


// Инициализация CMFCLibrary1App

BOOL CMFCLibrary1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

ustinovaTeaCollection collection;

extern "C"
{
	_declspec(dllexport) void __stdcall Add_From_File(const char* szPath)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.AddF(szPath);
	}

	_declspec(dllexport) void __stdcall Print_To_File(const char* szPath)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.PrintF(szPath);
	}

	_declspec(dllexport) void __stdcall Clear()
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.clearList();
	}

	_declspec(dllexport) int __stdcall GetSize() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return collection.ukazateli.size();
	}

	_declspec(dllexport) bool __stdcall GetTypeP1(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return static_pointer_cast<ustinovaFavouriteTea>(collection.ukazateli[index])->personal_rate;
	}

	_declspec(dllexport) void __stdcall GetTeaName(int index, char* str)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		strcpy(str, collection.ukazateli[index]->name);
	}

	_declspec(dllexport) void __stdcall GetTeaSort(int index, char* str)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		strcpy(str, collection.ukazateli[index]->sort);
	}

	_declspec(dllexport) int __stdcall GetTeaPrice(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return collection.ukazateli[index]->price;
	}

	_declspec(dllexport) int __stdcall GetTeaRate(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return collection.ukazateli[index]->rate;
	}

	_declspec(dllexport) int __stdcall GetTeaPersonalRate(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return static_pointer_cast<ustinovaFavouriteTea>(collection.ukazateli[index])->personal_rate;
	}

	_declspec(dllexport) void __stdcall CreateTea() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli.push_back(make_shared<ustinovaTea>());
	}

	_declspec(dllexport) void __stdcall CreateFavouriteTea() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli.push_back(make_shared<ustinovaFavouriteTea>());
	}

	_declspec(dllexport) void __stdcall SetTeaName(int index, char* newname)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli[index]->name = newname;
	}

	_declspec(dllexport) void __stdcall SetTeaSort(int index, char* newsort)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli[index]->sort = newsort;
	}

	_declspec(dllexport) void __stdcall SetTeaPrice(int index, int newprice)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli[index]->price = newprice;
	}

	_declspec(dllexport) void __stdcall SetTeaRate(int index, int newrate)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		collection.ukazateli[index]->rate = newrate;
	}

	_declspec(dllexport) void __stdcall SetTeaPersonalRate(int index, int newperrate)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		static_pointer_cast<ustinovaFavouriteTea>(collection.ukazateli[index])->personal_rate = newperrate;
	}
}
