#include "ustinova_tea.h"
#include <iostream>
#include <string>

using namespace std;

ustinova_tea::ustinova_tea()
{

}

ustinova_tea::~ustinova_tea()
{
}
void ustinova_tea::c_in()
{
			        cout << "������� �������� ���:";
		        getline(cin >> ws, name);

		        cout << "������� ��������� ������-�������������: ";
		        getline(cin >> ws, country_from);
		   
		        cout << "������� ��������� ��������-�������������: ";
		        getline(cin >> ws, company);
	
		        cout << "������� ���� ���: ";
		        getline(cin >> ws, country_from);
		  
		        cout << "�������� ����: ";
		        cin >> price;
		  
		        cout << "������� ���������������� ������ ���: ";
		        cin >> rate;
	
}
void ustinova_tea::c_out()
{
		cout << endl;
	    cout << "���" << endl << "��������: " << name << endl << "������-�������������: " << country_from << endl
	        << "��������-�������������: " << company<< endl << "����: " << sort << endl << "����: " << price
	        << endl << "���������������� ������: " << rate << endl;
}
void ustinova_tea::f_in(std::ifstream& fin) {
		getline(fin >> ws, name);
	    getline(fin >> ws, country_from);
	    getline(fin >> ws, company);
	    getline(fin >> ws, sort);
	    fin >> price;
	    fin >> rate;;
}
void ustinova_tea::f_out(std::ofstream& fout) {
	fout << name << endl << country_from << endl
		        << company << endl << sort << endl  << price
		        << endl << rate << endl;
}
//std::istream& operator>> (std::istream& in, ustinova_tea& tea)
//{
//    do {
//        cout << "������� �������� ���:";
//        getline(cin >> ws, tea.name);
//
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "������� ��������� ������-�������������: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "������� ��������� ��������-�������������: ";
//        getline(cin >> ws, tea.company);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "������� ���� ���: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "�������� ����: ";
//        cin >> tea.price;
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "������� ���������������� ������ ���: ";
//        cin >> tea.rate;
//    } while (cin.fail());
//
//    return in;
//}
//
//
//std::ostream& operator<< (std::ostream& out, const  ustinova_tea& tea)
//{
//    out << endl;
//    out << "���" << endl << "��������: " << tea.name << endl << "������-�������������: " << tea.country_from << endl
//        << "��������-�������������: " << tea.company<< endl << "����: " << tea.sort << endl << "����: " << tea.price
//        << endl << "���������������� ������: " << tea.rate << endl;
//    return out;
//}
//std::ifstream& operator>> (std::ifstream& fin, ustinova_tea& tea)
//{
//    getline(fin >> ws, tea.name);
//    getline(fin >> ws, tea.country_from);
//    getline(fin >> ws, tea.company);
//    getline(fin >> ws, tea.sort);
//    fin >> tea.price;
//    fin >> tea.rate;
//    return fin;
//}
//
//
//std::ofstream& operator<< (std::ofstream& fout, ustinova_tea& tea) {
//
//    fout  << tea.name << endl << tea.country_from << endl
//        << tea.company << endl << tea.sort << endl  << tea.price
//        << endl << tea.rate << endl;
//    return fout;
//}