#include <iostream>
#include "ustinova_tea.h"
#include "ustinova_teaCollection.h"
#include <fstream>
using namespace std;

int main()
{
    ustinova_teaCollection collection;
    setlocale(LC_ALL, "Russian");
    int com;
    while (1) {
        cout << "1.Добавить чай в коллекцию.\n2.Вывести спасок чая в коллекции.\n3.Загрузить коллекцию из файла.\n4.Сохранить коллекцию в файл.\n"
            << "5.Очистить коллекцию.\n0.Выход.\n"
            << "________________________________" << endl;

        cout << "Введите команду: ";
        cin >> com;

        switch (com)
        {
        case 1: {
            collection.add_tea();
            break;
        }
        case 2: {
            if (collection.ukazateli.size() == 0)
                cout << endl << "Коллекция пуста." << endl;
            else
                collection.c_out();
            break;
        }

        case 3: {

            ifstream fin;
            cout << "Введите имя файла: ";
            string ifileName;
            cin >> ws;
            getline(cin, ifileName);
            fin.open(ifileName, ios::in);
            if (fin.is_open())
            {
                collection.f_in(fin);
                fin.close();
                cout << "Загружено!" << endl;
            }
            else cout << "Файл не открывается." << endl;
            break;
        }
        case 4: {
            ofstream fout;
            cout << "Введите имя файла: ";
            string ofileName;
            cin >> ws;
            getline(cin, ofileName);
            fout.open(ofileName, ios::out);

            if (fout.is_open()) {
                collection.f_out(fout);
                fout.close();
                cout << "Сохранено!" << endl;
            }
            else cout << "Файл не открывается." << endl;
            break;
        }

        case 5: {
            collection.clear();
            cout << "Коллекция очищена." << endl;
            break;

        }
        case 0: {
            collection.clear();
            return 0;
            break;
        }
        default: {
            cout << "Нет такой команды.\n";
            break;
        }

        }
        cout << "________________________________" << endl;
    }

}
