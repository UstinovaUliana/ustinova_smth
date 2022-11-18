// ustinova_editDialog.cpp: файл реализации
//

#include "pch.h"
#include "UstinovaOOPP3.h"
#include "ustinova_editDialog.h"
#include "afxdialogex.h"
#include "UstinovaOOPP3Doc.h"

// Диалоговое окно ustinova_editDialog

IMPLEMENT_DYNAMIC(ustinova_editDialog, CDialogEx)

ustinova_editDialog::ustinova_editDialog(CUstinovaOOPP3Doc* pDoc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, NameText(_T(""))
	, SortText(_T(""))
	, PriceText(_T(""))
	, RateText(_T(""))
	, PerRateText(_T(""))
{
	Doc = pDoc;
}

ustinova_editDialog::~ustinova_editDialog()
{
}

void ustinova_editDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Listbox);
	DDX_Control(pDX, IDC_EDIT_NAME, NameEdit);
	DDX_Text(pDX, IDC_EDIT_NAME, NameText);
	DDX_Control(pDX, IDC_EDIT_SORT, SortEdit);
	DDX_Text(pDX, IDC_EDIT_SORT, SortText);
	DDX_Control(pDX, IDC_EDIT_PRICE, PriceEdit);
	DDX_Text(pDX, IDC_EDIT_PRICE, PriceText);
	DDX_Control(pDX, IDC_EDIT_RATE, RateEdit);
	DDX_Text(pDX, IDC_EDIT_RATE, RateText);
	DDX_Control(pDX, IDC_EDIT_PERRATE, PerRateEdit);
	DDX_Text(pDX, IDC_EDIT_PERRATE, PerRateText);
	DDX_Control(pDX, IDC_BUTTON_ADDTEA, AddTea);
	DDX_Control(pDX, IDC_BUTTON_ADDFAVTEA, AddFavTea);
	DDX_Control(pDX, IDC_BUTTON_DELETE, DeleteTea);
	DDX_Control(pDX, IDC_BUTTON_REDTEA, ChangeTea);
	DDX_Control(pDX, IDC_STATIC_PERRRATE, PerRateLabel);
}


BEGIN_MESSAGE_MAP(ustinova_editDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &ustinova_editDialog::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_REDTEA, &ustinova_editDialog::OnBnClickedButtonRedtea)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &ustinova_editDialog::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_ADDTEA, &ustinova_editDialog::OnBnClickedButtonAddtea)
	ON_BN_CLICKED(IDC_BUTTON_ADDFAVTEA, &ustinova_editDialog::OnBnClickedButtonAddfavtea)
	ON_BN_CLICKED(IDOK, &ustinova_editDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений ustinova_editDialog

BOOL ustinova_editDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Doc->collection.InitListBox(Listbox);

	//ChangeTea.EnableWindow(true);

	//Listbox.SetCurSel(pDoc->collection.ukazateli.size() - 1);
	//int pos = Listbox.GetCurSel();
	//if (pos < 0)
	//{
	//	ChangeTea.EnableWindow(false);
	//}

	//DeleteTea.EnableWindow(false);
	//NameEdit.EnableWindow(false);
	//SortEdit.EnableWindow(false);
	//PriceEdit.EnableWindow(false);
	//RateEdit.EnableWindow(false);
	//PerRateEdit.EnableWindow(false);
	//ok.EnableWindow(false);

	return TRUE;
}

void ustinova_editDialog::OnLbnSelchangeList1()
{
	// TODO: добавьте свой код обработчика уведомлений
	int pos = Listbox.GetCurSel();
	auto P = Doc->collection.ukazateli[pos];
	P->outputTea(this);
	UpdateData(FALSE);

	/*if (Listbox.GetCurSel() >= 0)
		del.EnableWindow(true);*/
}




void ustinova_editDialog::OnBnClickedButtonRedtea()
{
	// TODO: добавьте свой код обработчика уведомлений
	int pos = Listbox.GetCurSel();
	auto tea_ukaz = Doc->collection.ukazateli[pos];
	UpdateData(TRUE);
	tea_ukaz->inputTea(this);
	Listbox.DeleteString(pos);
	Listbox.InsertString(pos, Doc->collection.ukazateli[pos]->name);
	Listbox.SetCurSel(pos);
	//OnLbnSelchangeList1();
}


void ustinova_editDialog::OnBnClickedButtonDelete()
{
	// TODO: добавьте свой код обработчика уведомлений
	int pos = Listbox.GetCurSel();
	
	if (Doc->collection.ukazateli.size() == 1)
	{
		ChangeTea.EnableWindow(false);
		DeleteTea.EnableWindow(false);
	}
	for (int i = pos; i < Doc->collection.ukazateli.size() - 1; i++)
		Doc->collection.ukazateli[i] = Doc->collection.ukazateli[i + 1];
	Doc->collection.ukazateli.pop_back();
	Listbox.DeleteString(pos);
	if (pos < Doc->collection.ukazateli.size())
		Listbox.SetCurSel(pos);
	else
		Listbox.SetCurSel(pos - 1);
	UpdateData(TRUE);
	OnLbnSelchangeList1();
}


void ustinova_editDialog::OnBnClickedButtonAddtea()
{
	// TODO: добавьте свой код обработчика уведомлений
	int pos = Doc->collection.ukazateli.size();
	//auto P = Doc->collection.ukazateli[pos];
	ustinova_tea* ukaz = new ustinova_tea;
	ukaz->name = "New Tea";
	ukaz->sort = "";
	ukaz->price = 0;
	ukaz->rate = 0;

	Doc->collection.ukazateli.push_back(shared_ptr<ustinova_tea>(ukaz));
	UpdateData(TRUE);
//	OnLbnSelchangeList1();
	Listbox.InsertString(pos, Doc->collection.ukazateli[pos]->name);
	Listbox.SetCurSel(pos);
	OnLbnSelchangeList1();
}


void ustinova_editDialog::OnBnClickedButtonAddfavtea()
{
	// TODO: добавьте свой код обработчика уведомлений
	int pos = Doc->collection.ukazateli.size();
	//auto P = Doc->collection.ukazateli[pos];
	ustinova_favouriteTea* ukaz = new ustinova_favouriteTea;
	ukaz->name = "New Favourite Tea";
	ukaz->sort = "";
	ukaz->price = 0;
	ukaz->rate = 0;
	ukaz->personal_rate = 0;

	Doc->collection.ukazateli.push_back(shared_ptr<ustinova_tea>(ukaz));
	UpdateData(TRUE);
	//	OnLbnSelchangeList1();
	Listbox.InsertString(pos, Doc->collection.ukazateli[pos]->name);
	Listbox.SetCurSel(pos);
	OnLbnSelchangeList1();
}


void ustinova_editDialog::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
