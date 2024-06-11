#include <iostream>
#include <cstdlib>
#include <ctime>

int findTriplets(const int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size - 2; i++) {
        if (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2]) {
            count++;
        }
    }
    return count;
}

int main() {
    const int arr1[] = {3, 2, 1, 0, -1, -2, -3};
    const int arr2[] = {3, 2, 1, 0, 5, 4, 3, 2, 1, 0};
    const int arr3[] = {3, 2};
    
    
    std::cout << "Упорядоченные тройки в arr1: " << findTriplets(arr1, 7) << std::endl;
    std::cout << "Упорядоченные тройки в arr2: " << findTriplets(arr2, 10) << std::endl;
    std::cout << "Упорядоченные тройки в arr3: " << findTriplets(arr3, 2) << std::endl;
 
    // Динамический массив
    int size;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> size;

    int* arr4 = new int[size];
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr4[i] = rand() % 10-20; 
    }

    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Упорядоченные тройки в arr4: " << findTriplets(arr4, size) << std::endl;
    delete[] arr4; 
    return 0;
}
