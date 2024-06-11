// Ilia Shemiakin, 2022
// Циклы и ветвления

#include <iostream>

int main()
{
    // Цикл while и оператор switch

    std::cout << "Enter 1, 2, 3 or 0 to exit:\n";
    char choice = '0';
    std::cin >> choice;
    while (choice != '0')
    {
        switch (choice)
        {
        case '1':
            std::cout << "\"ONE\"\n";
            // обратите внимание на отсутствие break
        case '2':
            std::cout << "\"TWO\"\n";
            break;
        case '3':
            std::cout << "\"THREE\"\n";
            break;
        default:
            std::cout << "Try again\n";
        }
        std::cin >> choice;
    }
    std::cout << "The End\n";

    std::cout << '\n';

    // Бесконечный цикл while(true), операторы break и continue

    // обратите внимание, как условиями if в сочетании с операторами break и continue можно 
    // управлять выполнением цикла;
    // в реальности следует использовать не бесконечный цикл + break,
    // а цикл с правильно сформулированным условием

    // если вводится нечётное число, то оно выводится и выполнение продолжается,
    // если число чётное - выводится оно само и его половина;
    std::cout << "Enter integer number or \"0\" to exit: ";
    while (true)
    {
        int num = 0;
        std::cin >> num;
        // если введён 0, то бесконечный цикл прервётся из-за break
        if (num == 0)
        {
            break;
        }
        // если число окажется нечётным, то после вывода начнётся новая итерация цикла из-за continue
        if (num % 2 != 0)
        {
            std::cout << num << " is odd\n";
            continue;
        }
        // условие if (num % 2 == 0) не требуется,
        // т.к. если это условие не выполнено (т.е. num == 0 или num % 2 != 0),
        // то программа просто не дойдёт до выполнения следующей строки
        std::cout << num << " is even, half of " << num << " is " << num / 2 << '\n';
    }

    std::cout << "The End\n";

    std::cout << '\n';

    // Цикл do..while

    // рекомендуется избегать цикла do..while, предпочитая ему цикл с предусловием while

    int i = 0;
    std::cout << "Enter integer number or \"0\" to exit:\n";
    // первая итерация цикла будет выполнена независимо от начального значения i
    do
    {
        std::cin >> i;
        std::cout << "your number is: " << i << '\n';
    } while (i != 0);

    std::cout << "The End\n";

    std::cout << '\n';

    // Вложенные циклы

    const int N = 7;
    for (int i = 0; i < N; i++)
    {
        // внутренний цикл запускается заново на каждой итерации внешнего
        for (int j = 0; j < N; j++)
        {
            // обратите внимание на то, в каких комбинациях и в каком порядке будут выводиться индексы
            std::cout << "  (i=" << i << ";j=" << j << ")";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    // вывод треугольника из '*'
    const int SIZE = 10;
    for (int i = 0; i < SIZE; i++)
    {
        // обратите внимание, что количество итераций внутреннего цикла зависит от i
        for (int j = i; j < SIZE; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
