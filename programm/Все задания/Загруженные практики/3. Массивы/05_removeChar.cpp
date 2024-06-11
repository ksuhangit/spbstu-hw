#include <iostream>
#include <string>

void removeChar(std::string& str, char ch) {
    std::string newStr = "";
    for (char c : str) {
        if (c != ch) {
            newStr += c;
        }
    }
    str = newStr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string str;
    char ch;
    std::cout << "Введите строку: ";
    std::cin >> str;

    std::cout << "Введите символ для удаления: ";
    std::cin >> ch;

    removeChar(str, ch);

    std::cout << "Исходная строка: " << str << std::endl;

    return 0;
}
