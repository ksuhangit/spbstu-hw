#include <iostream>
#include <string>

bool Palindrome(int num) {
    std::string binary = "";

    // Преобразование числа в двоичную строку
    while (num > 0) {
        binary = std::to_string(num % 2) + binary;
        num /= 2;
    }

    // Проверка, является ли строка палиндромом
    int left = 0, right = binary.length() - 1;
    while (left < right) {
        if (binary[left] != binary[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int number;

    do {
        std::cout << "Введите положительное число: ";
        std::cin >> number;

        if (number <= 0) {
            std::cout << "Неверно! Введите положительное число." << std::endl;
        }
    } while (number <= 0);

    if (Palindrome(number)) {
        std::cout << "Число является палиндромом в двоичной системе счисления";
    }
    else {
        std::cout << "Число не является палиндромом в двоичной системе счисления";
    }

    return 0;
}
