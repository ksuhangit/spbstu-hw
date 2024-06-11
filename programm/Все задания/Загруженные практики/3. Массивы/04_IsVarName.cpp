#include <iostream>
#include <cctype>

bool isVarName(const std::string& name) {
    if (name.empty() || isdigit(name[0])) {
        return false;
    }

    for (char c : name) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string name;
    std::cout << "Введите имя переменной: ";
    std::cin >> name;

    if (isVarName(name)) {
        std::cout << "Допустимое имя переменной" << std::endl;
    }
    else {
        std::cout << "Неверное имя переменной" << std::endl;
    }

    return 0;
}
