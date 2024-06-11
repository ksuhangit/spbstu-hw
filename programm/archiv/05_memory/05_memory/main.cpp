#include "LinkedList.h"

int main() {
    LinkedList list1;
    list1.addElement(2);
    list1.addElement(1);
    list1.addElement(6);
    list1.addElement(3);
    

    LinkedList list2;
    list2.addElement(4);
    list2.addElement(7);
    list2.addElement(10);
    list2.addElement(5);

    std::cout << "List 1: " << list1 << std::endl;
    std::cout << "List 2: " << list2 << std::endl;

    LinkedList combined = list1.combine(list2);
    std::cout << "Combined List: " << combined << std::endl;

    return 0;
}