// 1_1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
void foo(int a[])
{
    std::cout << a[0] << '\n';
    std::cout << sizeof(a) / sizeof(a[0]) << '\n';
}


int main()
{
    int arr[]{ 1, 2, 3, 4 };
    std::cout << arr[0] << '\n';
    std::cout << *arr << '\n';
    std::cout << sizeof(arr) << '\n';
    std::cout << sizeof(arr) / sizeof(arr[0]) << '\n'; //���-�� ��������� �������
    std::cout << arr[2] << '\n';
    std::cout << 2[arr] << '\n';
    foo(arr);
    std::cout << '\n'
        int* pArr = new int[5] {10, 20, 30, 40, 50};
    std::cout << pArr[1] << '\n';
    return 0;
}
