// Напишите функцию isOrdered, имеющую два параметра – адрес
// одномерного массива целых чисел и количество элементов,
//возвращающую значение true, если элементы массива упорядочены по
// возрастанию, и false в противном случае.

#include <iostream>
#include <clocale>

bool isOrdered(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr1[] = { 1 };
    int arr2[] = { 5, 4, 3, 2, 1 };

    if (isOrdered(arr1, 5)) {
        std::cout << "Элементы массива 1 упорядочены." << std::endl;
    }
    else {
        std::cout << "Элементы массива 1 не упорядочны." << std::endl;
    }

    if (isOrdered(arr2, 5)) {
        std::cout << "Элементы массива 2 упорядочены." << std::endl;
    }
    else {
        std::cout << "Элементы массива 2 не упорядочены." << std::endl;
    }

    return 0;
}

