#pragma once
#include "UstinovaOOPP3Doc.h"

// Диалоговое окно ustinova_editDialog
class CUstinovaOOPP3Doc;

class ustinova_editDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ustinova_editDialog)


public:
	ustinova_editDialog(CUstinovaOOPP3Doc* pDoc, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ustinova_editDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CUstinovaOOPP3Doc* Doc;
	CListBox Listbox;
	CEdit NameEdit;
	CString NameText;
	CEdit SortEdit;
	CString SortText;
	CEdit PriceEdit;
	CString PriceText;
	CEdit RateEdit;
	CString RateText;
	CEdit PerRateEdit;
	CString PerRateText;
	CButton AddTea;
	CButton AddFavTea;
	CButton DeleteTea;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	CButton ChangeTea;
	afx_msg void OnBnClickedButtonRedtea();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonAddtea();
	afx_msg void OnBnClickedButtonAddfavtea();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CStatic PerRateLabel;
};
