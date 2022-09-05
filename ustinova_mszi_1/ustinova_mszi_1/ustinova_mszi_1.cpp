
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
void coding(std::string file_in, std::string file_out, int choose) {
    std::ifstream fin;
    std::ofstream fout;
    fin.open(file_in);
    fout.open(file_out);
    const int length = 33;
    char alph[length] = {'А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я'};
    char* input_key = new char[255]; // на время выделяется память (с запасом) под строку 
    std::cin.getline(input_key, 255); // чтение строки

    char* key = new char[strlen(input_key) + 1]; // выделяется новая память под размер введённой строки
    strcpy(key, input_key); // копируется строка в новую память
    std::vector <int> keyPoses;
    delete[] input_key; // ненужная память освобождается

    for (int i = 1; i <= strlen(key); i++) {
        for (int j = 0; j < length; j++) {
            if (key[i] == alph[j]) {
                keyPoses.push_back(j);
            }
        }
    }

    std::vector <vector <char>> table(strlen(key),vector<char>(32));
    for (int j = 0; j < keyPoses.size(); j++) {
        cout << keyPoses[j]<<" ";
        int t = keyPoses[j];
        int k = 0;
        for (int i = t; i < length; i++) {
            table[j][k] = alph[i];
            k++;
        }
        for (int i = 0; i < t; i++) {
            table[j][k] = alph[i];
            k++;
        }
    }
    cout << "\n";
   
        char letter;
        char coded;
        int j = 1;
        if (!fin.is_open())
            cout << "Ошибка в имени файла!!!\n";
        else
            while (fin.get(letter)) {
                int i;
                if (choose == 1) {
                    for (int i = 1; i <= 33; i++) {
                        if (j == strlen(key) + 1) j = 1;
                        if (letter == alph[i])
                        {
                            coded = table[j][i];
                            fout << coded;
                            j++;
                        }
                    }
                }
                else {
                    for (int i = 1; i <= 33; i++) {
                        if (j == strlen(key) + 1) j = 1;
                        if (letter == table[j][i])
                        {
                            coded = alph[i];
                            fout << coded;
                            j++;
                        }
                    }
                   
                }

            }
        fin.close();
        fout.close();
   
}

int main()
{
    std::ios::sync_with_stdio(false);
    setlocale(LC_ALL, "Russian");
    int action;
    std::string output_file, input_file;


    while (1) {
        std::cout << "\n\nМетод Вижинера\n1) Зашифровать текст\n2) Расшифровать текст\n0) Выход\n\n";
        std::cin >> action;
        switch (action) {
        case 1: {
            std::cout << "\nВведите имя файла для считывания текста:\n";
            std::cin.get();
            getline(std::cin, input_file);
            output_file = "encoded.txt";
            coding(input_file, output_file, action);
            std::cout << "\nЗашифрованный текст сохранён в encoded.txt!\n";
            break;
        }
        case 2: {
        std:: cout << "\nВведите имя файла для считывания текста:\n";
            std::cin.get();
            getline(std::cin, input_file);
            output_file = "decoded.txt";
            coding(input_file, output_file, action);
            std::cout << "\nРасшифрованный текст сохранён в decoded.txt!\n";
            break;
        }
        case 0: {
            return(0);
            break;
        }
        default: {
            std::cout << "\n\nТакого пункта нет.\n\n";
            break;
        }
        }
    }
}

