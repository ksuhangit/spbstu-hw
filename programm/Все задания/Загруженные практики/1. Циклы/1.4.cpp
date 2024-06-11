// Напишите программу, выполняющую ввод последовательности целых чисел, признаком конца которой будет ввод числа ноль(ноль 
// не считается членом последовательности) и определяющую :
// 1) сумму всех введенных чисел
// 2) среднее арифметическое всех введенных чисел
// 3) среднее арифметическое введенных положительных чисел
// 4) максимальное значение и его номер среди всех введенных чисел
// 5) минимальное положительное значение и его номер среди всех введенных чисел
// Замечания :
// 1) Нельзя использовать массивы
// 2) При решении использовать только цикл с предусловием

#include <iostream>

int main() {
    int num, sum = 0, count = 0, sumPos = 0, countPos = 0, max = INT_MIN, maxPos = 0, minPos = INT_MAX, minPosNum = 0;

    std::cout << "Write the sequence (enter 0 to exit):\n";
    std::cin >> num;

    while (num != 0) {
        sum += num;
        count++;
        if (num > 0) {
            sumPos += num;
            countPos++;

            if (num < minPos) {
                minPos = num;
                minPosNum = count;
            }
        }

        if (num > max) {
            max = num;
            maxPos = count;
        }

        std::cin >> num;
    }
    double average = static_cast<double>(sum) / count;
    double averagePos = 0;
    if (countPos > 0) {
        averagePos = static_cast<double>(sumPos) / countPos;
    }

    std::cout << "1. Sum all numbers: " << sum << std::endl;
    std::cout << "2. Average all numbers: " << average << std::endl;
    std::cout << "3. Average all positive numbers: " << averagePos << std::endl;
    std::cout << "4. Max value and the number of all the entered: " << max << " (position " << maxPos << ")" << std::endl;
    std::cout << "5. Min value positive number and the number of all the entered: " << minPos << " (position " << minPosNum << ")" << std::endl;

    return 0;
}