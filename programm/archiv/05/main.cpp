#include <iostream>
#include "SortedList.h"
using namespace std;
int main() {
	SortedList list1;	//���������� �� ���������
	list1.add(5);
	list1.add(1);
	list1.add(3);
	cout << "List 1: " << list1 << endl;

	SortedList list2;	//���������� �� ���������
	list2.add(4);
	list2.add(2);
	list2.add(6);
	list2.add(5);
	cout << "List 2: " << list2 << endl;

	SortedList list3 = list1.merge(list2);	//���������� ����������� �����������
	cout << "Merged List: " << list3 << endl;

	SortedList list4(list3);	//���������� ����������� �����������
	cout << "Copied List: " << list4 << endl;

	SortedList list5(move(list3));	//���������� ����������� �����������
	cout << "Moved List: " << list5 << endl;
	cout << "Original List after move: " << list3 << endl;

	list5 = list2;		//���������� �������� ����������� ������������
	cout << "List 5 after assignment: " << list5 << endl;
	// ������ ������������� ������������
	list5 = move(list4);
	cout << "List 5 after move assignment: " << list5 << endl;
	cout << "List 4 after move assignment: " << list4 << endl;
	list1.add(7);
	cout << "List 1 after adding 7: " << list1 << endl;

	cout << "List 1 contains 6? " << list1.contains(6) << endl;
	cout << "List 1 contains 7? " << list1.contains(7) << endl;

	system("pause");
	return 0;
}
