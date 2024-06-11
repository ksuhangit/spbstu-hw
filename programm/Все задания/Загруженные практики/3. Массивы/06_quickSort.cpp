#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);

        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr;
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        arr.push_back(element);
    }

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Сортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
