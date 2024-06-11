#include <iostream>
#include "SortedList.h"
using namespace std;

int main() {
	SortedList list1;	//конструтор по умолчанию
	list1.add(5);
	list1.add(1);
	list1.add(3);
	cout << "1 список :  " << list1 << endl;

	SortedList list2;	//конструтор по умолчанию
	list2.add(4);
	list2.add(2);
	list2.add(6);
	list2.add(5);
	cout << "2 список :  " << list2 << endl;

	SortedList list3 = list1.merge(list2);	//вызывается конструктор перемещения
	cout << "3 объединенный список :  " << list3 << endl;

	SortedList list4(list3);	//вызывается конструктор копирования
	cout << "4 скопированный список :  " << list4 << endl;

	SortedList list5(move(list3));	//вызывается конструктор перемещения
	cout << "5 перемещенный список :  " << list5 << endl;
	cout << "Исходный список после пемещения :  " << list3 << endl;


	cout << endl; 
	list5 = list2;		//вызывается Оператор копирующего присваивания
	cout << "Список 5 после копирующего присваивания Списка 2 : " << list5 << endl;
	
	
	// Пример перемещающего присваивания
	list5 = move(list4);
	cout << "Список 5 после перемещения Списка 4: " << list5 << endl;
	cout << "Список 4 после перемешения в Список 5: " << list4 << endl;
	
	cout << endl; 
	list1.add(7);
	cout << "Список 1 после добавления 7: " << list1 << endl;

	cout << "Список 1 содержит 6? " << list1.contains(6) << endl;
	cout << "Список 1 содержит 7? " << list1.contains(7) << endl;

	system("pause");
	return 0;
}
