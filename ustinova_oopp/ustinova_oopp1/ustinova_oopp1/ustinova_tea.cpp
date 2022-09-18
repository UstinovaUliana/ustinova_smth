#include "ustinova_tea.h"

ustinova_tea::ustinova_tea()
{
}

ustinova_tea::~ustinova_tea()
{
}

IMPLEMENT_SERIAL(ustinova_tea, CObject, 1)

void ustinova_tea::c_in()
{
	string sname, scountry_from, scompany, ssort;

			        cout << "Введите название чая:";
		        getline(cin >> ws, sname);

		   /*     cout << "Введите назвавние страны-производителя: ";
		        getline(cin >> ws, scountry_from);
		   
		        cout << "Введите назвавние компании-производителя: ";
		        getline(cin >> ws, scompany);*/
	
		        cout << "Введите сорт чая: ";
		        getline(cin >> ws, ssort);
				name = sname.c_str();
				country_from = scountry_from.c_str();
				company = scompany.c_str();
				sort = ssort.c_str();

		        cout << "Ввведите цену: ";
		        cin >> price;
		  
		        cout << "Введите пользовательскую оценку чая: ";
		        cin >> rate;
	
}
void ustinova_tea::c_out()
{
		cout << endl;
	    cout << "Чай" << endl << "Название: " << (LPCTSTR)name << "; " 
			//<< "Страна-производитель: " << (LPCTSTR)country_from << "; "   << "Компания-производитель: " << (LPCTSTR)company << "; "
			<< "Сорт: " << (LPCTSTR)sort << "; "  << "Цена: " << price  << "; "  << "Пользовательская оценка: " << rate << endl;
}

void ustinova_tea::Serialize(CArchive& file) {
	if (file.IsStoring()) {
		file << name 
			//<< country_from  << company  
			<< sort  << price      << rate ;
	}
	else {
		file >> name 
			//>> country_from >> company 
			>> sort >> price >> rate;
	}
}

//void ustinova_tea::f_in(std::ifstream& fin) {
//		getline(fin >> ws, name);
//	    getline(fin >> ws, country_from);
//	    getline(fin >> ws, company);
//	    getline(fin >> ws, sort);
//	    fin >> price;
//	    fin >> rate;
//}
//void ustinova_tea::f_out(std::ofstream& fout) {
//	fout << name << endl << country_from << endl
//		        << company << endl << sort << endl  << price
//		        << endl << rate << endl;
//}

//std::istream& operator>> (std::istream& in, ustinova_tea& tea)
//{
//    do {
//        cout << "Введите название чая:";
//        getline(cin >> ws, tea.name);
//
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "Введите назвавние страны-производителя: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "Введите назвавние компании-производителя: ";
//        getline(cin >> ws, tea.company);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "Введите сорт чая: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "Ввведите цену: ";
//        cin >> tea.price;
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "Введите пользовательскую оценку чая: ";
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
//    out << "Чай" << endl << "Название: " << tea.name << endl << "Страна-производитель: " << tea.country_from << endl
//        << "Компания-производитель: " << tea.company<< endl << "Сорт: " << tea.sort << endl << "Цена: " << tea.price
//        << endl << "Пользовательская оценка: " << tea.rate << endl;
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