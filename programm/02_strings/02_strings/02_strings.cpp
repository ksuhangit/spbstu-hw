#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void replaceCharInCStyle(char* str, char oldChar, char newChar) {
    while (*str) {
        if (*str == oldChar) {
            *str = newChar;
        }
        str++;
    }
}

void replaceCharInStringStyle(string& str, char oldChar, char newChar) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Ошибка открытия файла!";
        return 1;
    }

    char oldChar, newChar;
    string lengthStr;
    char* str = nullptr;

    while (getline(file, lengthStr)) {
        int length = atoi(lengthStr.c_str());
        str = new char[length + 1];

        if (!file.eof()) {
            file.getline(str, length + 1);
            cout << "Исходная строка: " << str << endl;

            cout << "Введите символ, который нужно заменить: ";
            cin >> oldChar;

            cout << "Введите символ, на который нужно заменить: ";
            cin >> newChar;

            replaceCharInCStyle(str, oldChar, newChar);
            cout << "После преобразования для строки в стиле С: " << str << endl;
            
            string str2 = str;
            replaceCharInStringStyle(str2, oldChar, newChar);
            cout << "После преобразования для строки в стиле c++ (std::string): " << str2 << endl;
        }
        delete[] str;
    }
    file.close();
    return 0;
}
