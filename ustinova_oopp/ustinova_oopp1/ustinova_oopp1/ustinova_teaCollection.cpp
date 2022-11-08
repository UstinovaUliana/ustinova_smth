#include "ustinova_teaCollection.h"

ustinova_teaCollection::ustinova_teaCollection()
{

}

ustinova_teaCollection::~ustinova_teaCollection()
{
	clear();
}

void ustinova_teaCollection::add_tea(bool is_favourite)
{
	//auto tea = make_shared<ustinova_tea>();
	//tea.c_in()
	//ustinova_tea* ukaz = new ustinova_tea;
	//ukaz->c_in();
	//ukazateli.push_back(tea.get());
	//ustinova_tea tea;
	//tea.c_in();
	shared_ptr<ustinova_tea> ukaz;
	if (is_favourite) ukaz = make_shared<ustinova_favouriteTea>();
	else ukaz = make_shared<ustinova_tea>();
	(*ukaz).c_in();
	ukazateli.push_back(ukaz);
}

void ustinova_teaCollection::c_out()
{
	cout << endl;
	  /*  for (int i = 0; i < ukazateli.size(); i++)
	(*ukazateli[i]).c_out();*/

	for (auto i = ukazateli.begin(); i < ukazateli.end(); ++i)
		(*i)->c_out();
}
void ustinova_teaCollection::f_in(string file_name) {
		ukazateli.clear();
		CFile file((LPCTSTR)(file_name.c_str()), CFile::modeRead);
		CArchive arch(&file, CArchive::load);
		int size,n;
	    arch >> size;
		/*arch >> n;*/
		for (int i = 0; i < size; i++) {
			ustinova_tea* ukaz = new ustinova_tea;
			arch >> ukaz;
			shared_ptr<ustinova_tea> shared_ukaz(ukaz);
			ukazateli.push_back(shared_ukaz);
		}

		arch.Close();
		file.Close();
}
void ustinova_teaCollection::f_out(string file_name) {
	CFile file((LPCTSTR)(file_name.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive arch(&file, CArchive::store);
	   arch << ukazateli.size();
	   for (auto ukaz : ukazateli)  arch << ukaz.get();
	   arch.Close();
	   file.Close();
}
void ustinova_teaCollection::clear()
{
	for (auto ukaz: ukazateli) *ukaz;
	ukazateli.clear();
}
//
//std::istream& operator>> (std::istream& in, ustinova_teaCollection& collection)
//{
//    do {
//        cout << "¬ведите название коллекции:";
//        getline(cin >> ws, tea.name);
//
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "¬ведите назвавние страны-производител€: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "¬ведите назвавние компании-производител€: ";
//        getline(cin >> ws, tea.company);
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "¬ведите сорт ча€: ";
//        getline(cin >> ws, tea.country_from);
//    } while (cin.fail());
//
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "¬введите цену: ";
//        cin >> tea.price;
//    } while (cin.fail());
//    do {
//        cin.clear();
//        cin.ignore(2000, '\n');
//        cout << "¬ведите пользовательскую оценку ча€: ";
//        cin >> tea.rate;
//    } while (cin.fail());
//
//    return in;
//}
//
//
//std::ostream& operator<< (std::ostream& out, const  ustinova_teaCollection& collection)
//{
//    out << endl;
//    for (int i = 0; i < collection.ukazateli.size(); i++)
//        out << *collection.ukazateli[i];
//    return out;
//}
//std::ifstream& operator>> (std::ifstream& fin, ustinova_teaCollection& collection)
//{
//    int size;
//    fin >> size;
//    for (int i = 0; i < size; i++)
//        fin>> *collection.ukazateli[i];
//    return fin;
//}
//
//
//std::ofstream& operator<< (std::ofstream& fout, ustinova_teaCollection& collection) {
//
//    fout << endl;
//    fout << collection.ukazateli.size() << endl;
//    for (int i = 0; i < collection.ukazateli.size(); i++)
//        fout << *collection.ukazateli[i];
//    return fout;
//}


