// 1.6.cpp 

#include <iostream>
#include <vector>
#include <string>

int main() {
    int number;
    const int MAX_VAL = 400;
    const int MIN_VAL = 0;

    std::cout << "Enter an integer (a < 400): ";
    std::cin >> number;

    if (number <= MIN_VAL || number >= MAX_VAL) {
        std::cout << "The number must satisfy the condition 0 < a < 400" << std::endl;
        return 0;
    }

    std::string romanNumeral = "";
    std::vector<int> values = { 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    std::vector<std::string> numerals = { "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 9; i++) {
        while (number >= values[i]) {
            number -= values[i];
            romanNumeral += numerals[i];
        }
    }

    std::cout << "Roman number: " << romanNumeral << std::endl;

    return 0;
}