#include <iostream> 
#include <vector>

int findValue(const std::vector<int>& arr, int value, int start, int end) {
    if (start > end) { 
        if (end < 0) return start; 
        else if (start >= arr.size()) 
            return end; 
        else return (value - arr[end] < arr[start] - value) ? end : start; }


    int mid = start + (end - start) / 2;

    if (arr[mid] == value) {
        return mid;
    }
    else if (arr[mid] < value) {
        return findValue(arr, value, mid + 1, end);
    }
    else {
        return findValue(arr, value, start, mid - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15 }; 
    int value;


    std::cout << "Введите значение: ";
    std::cin >> value;

    int index = findValue(arr, value, 0, arr.size() - 1);

    std::cout << "Ближайшее значение к " << value << " в массиве есть: " << arr[index] << " по индексу " << index << std::endl;

    return 0;
}