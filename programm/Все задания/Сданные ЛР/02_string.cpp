//Сформировать новую строку, заменив в исходной строке все вхождения одного заданного символа на другой заданный символ.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char* changeSymbol(char* destination, const char* source, char from, char to) {
    while (*source != '\0'){
        if (*source == from) {
            *destination = to;
        }
        else {
            *destination = *source;
        }
        source++;
        destination++;
    } 
    *destination = '\0';
    return destination;
}

string changeSymbol(const string& source, char from, char to) {
    string destination(source.size(), '\0'); 
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == from) {
            destination[i] = to;
        }
        else {
            destination[i] = source[i];
        }
    }
    return destination;
}

int main() {
 
    ifstream file("input.txt");
    if (file.is_open()) {
        char from, to;
        cout << "Введите символ, который нужно заменить: ";
        cin >> from;
        cout << "Введите символ, на который нужно заменить: ";
        cin >> to;
        cin.ignore();
  
        int n; 
        char* str = nullptr; 
        
        try {
            while (file >> n) {
                cout << "--------" << endl;

                file.ignore();
                str = new char[(n + 1) * 2 ]; 
                file.getline(str, n + 1); 


                char* newStrC = str + n + 1;
                changeSymbol(newStrC, str, from, to);
                cout << "После преобразования для строки в стиле C" << endl;
                cout << "Исходная строка: " << str << endl;
                cout << "Новая строка: " << newStrC << endl;

                string strCpp = str;
                string newStrCpp = changeSymbol(strCpp, from, to);
                cout << "После преобразования для строки в стиле C++ (std::string)" << endl;
                cout << "Исходная строка: " << strCpp << endl;
                cout << "Новая строка: " << newStrCpp << endl;

                delete[] str;
            }
        }
        catch (...) {
            cout << "Ошибка выделения памяти" << endl;
            delete[] str;
        }
        file.close();
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }

    return 0;
}
