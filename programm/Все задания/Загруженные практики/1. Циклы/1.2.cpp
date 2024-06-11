//Заданы координаты слона, стоящего на клетке шахматной доски (номер строки и номер столбца).Напишите цикл(или циклы) для вывода координат всех клеток, 
// находящихся под ударом.Слон ходит на любое число полей по диагонали.

#include <iostream>

int main() {
    int row, col;
    const int DESK_MAX = 8;
    const int DESK_MIN = 1;

    std::cout << "Enter the row number of the bishop: ";
    std::cin >> row;
    std::cout << "Enter the column number of the bishop: ";
    std::cin >> col;

    std::cout << "Cells under attack by the bishop:" << std::endl;

    int i, j;

    i = row - 1;
    j = col - 1;
    while (i >= DESK_MIN && j >= DESK_MIN) {
        std::cout << "Row: " << i << ", Column: " << j << std::endl;
        i--;
        j--;
    }

    i = row - 1;
    j = col + 1;
    while (i >= DESK_MIN && j <= DESK_MAX) {
        std::cout << "Row: " << i << ", Column: " << j << std::endl;
        i--;
        j++;
    }

    i = row + 1;
    j = col - 1;
    while (i <= DESK_MAX && j >= DESK_MIN) {
        std::cout << "Row: " << i << ", Column: " << j << std::endl;
        i++;
        j--;
    }

    i = row + 1;
    j = col + 1;
    while (i <= DESK_MAX && j <= DESK_MAX) {
        std::cout << "Row: " << i << ", Column: " << j << std::endl;
        i++;
        j++;
    }

    return 0;
}