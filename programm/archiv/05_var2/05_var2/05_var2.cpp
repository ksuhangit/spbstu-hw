#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list1;
    list1.insert(3);
    list1.insert(1);
    list1.insert(5);
    list1.insert(8);
    list1.insert(2);

    std::cout << "List 1: " << list1 << std::endl;

    LinkedList<int> list2;
    list2.insert(4);
    list2.insert(6);
    list2.insert(2);
    list2.insert(9);
    list2.insert(10);

    std::cout << "List 2: " << list2 << std::endl;

    LinkedList<int> merged_list = list1.merge(list2);
    std::cout << "Merged List: " << merged_list << std::endl;

    return 0;
}