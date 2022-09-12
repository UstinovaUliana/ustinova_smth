
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void coding(std::string input_file, std::string output_file, int action) {
    std::ifstream fin;
    std::ofstream fout;
    string keyword;
    char letter, coded_letter;

    cout << "Введите ключевое слово:";
    cin >> ws;
    getline(cin, keyword);

    fin.open(input_file, ios::binary);
    fout.open(output_file, ios::binary);
    
        int keyword_letter_code = 0;
        if (!fin.is_open())
            cout << "Невозможно открыть файл.\n";
        else
            while (fin.get(letter)) {
               
                if (action == 1) {
                    coded_letter = letter + keyword_letter_code;
                    fout << coded_letter;
                }
                else {
                    coded_letter = letter - keyword_letter_code;
                    fout << coded_letter;
                }
                keyword_letter_code++;
                if (keyword_letter_code > keyword.size()) keyword_letter_code = 0;
            }
        fin.close();
        fout.close();
   
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int action;
    string output_file, input_file;


    while (1) {
        cout << "Выберите операцию: \n1) Зашифровать текст;\n2) Расшифровать текст;\n0) Выход.\n\n";
        cin >> action;
        switch (action) {
        case 1: {
            cout << "\nВведите название файла с исходным текстом: ";
            cin>>ws;
            getline(cin, input_file);
            cout << "\nВведите название файла, куда будет сохранён зашифрованный текст: ";
            cin >> ws;
            getline(cin, output_file);
            coding(input_file, output_file, action);
            std::cout << "\nШифрование выполнено.\n\n";
            break;
        }
        case 2: {
            cout << "\nВведите название файла с исходным текстом: ";
            cin>>ws;
            getline(cin, input_file);
            cout << "\nВведите название файла, куда будет сохранён зашифрованный текст: ";
            cin >> ws;
            getline(cin, output_file);
            coding(input_file, output_file, action);
            cout << "\nДешифровка выполнена.\n\n";
            break;
        }
        case 0: {
            return(0);
            break;
        }
        default: {
            cout << "\nТакой операции нет.\n\n";
            break;
        }
        }
    }
}

