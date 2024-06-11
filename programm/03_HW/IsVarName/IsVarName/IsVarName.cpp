//Напишите функцию isVarName, имеющую один параметр(символьна строка) и 
// проверяющую правильность имени переменной в C++.Имя
// может содержать только латинские буквы(заглавные и строчные), цифры
// и знак подчёркивания, но не может начинаться с цифры.Функция должна
// возвращать true, если имя записано правильно, false – в противном случае.
// Можно использовать библиотечные функции из файла <cctype>.

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
