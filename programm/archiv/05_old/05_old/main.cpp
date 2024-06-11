#include <iostream>
#include "SortedList.h"
using namespace std;
int main() {
	SortedList list1;	//конструтор по умолчанию
	list1.add(1);
	list1.add(5);
	list1.add(3);
	cout << "1 список :  " << list1 << endl;

	SortedList list2;	//конструтор по умолчанию
	list2.add(4);
	list2.add(2);
	list2.add(6);
	list2.add(5);
	cout << "2 список :  " << list2 << endl;
	cout << endl;

	SortedList list3 = list1.merge(list2);	//вызывается конструктор перемещения
	cout << "3 список - объединение 1 и 2 списков :  " << list3 << endl;
	cout << endl;

	SortedList list4(list3);	//вызывается конструктор копирования
	cout << "4 список - скопировано из 3 списка :  " << list4 << endl;
	cout << endl;

	SortedList list5(move(list3));	//вызывается конструктор перемещения
	cout << "5 список - перемещенный список из 3 списка :  " << list5 << endl;
	cout << "Исходный 3 список после перемещения :  " << list3 << endl;
	cout << endl;

	SortedList list6 = list3.merge(list3);
	cout << "6 список - объединенный 3 пустой список :  " << list6 << endl;
	cout << endl;

	SortedList list7 = list1.merge(list6);
	cout << "7 список - объединенный 6 пустой и 1 списки :  " << list7 << endl;
	cout << endl;

	list5 = list2;		//вызывается Оператор копирующего присваивания
	cout << "5 список после копирующего присваивания 2 списка : " << list5 << endl;
	cout << endl;

	// Пример перемещающего присваивания
	list5 = move(list4);
	cout << "5 список после перемещения 4 списка : " << list5 << endl;
	cout << "4 список после перемешения в 5 список : " << list4 << endl;



	cout << endl;
	list1.add(7);
	cout << "Список 1 после добавления 7: " << list1 << endl;

	cout << "Список 1 содержит 6? " << list1.contains(6) << endl;
	cout << "Список 1 содержит 7? " << list1.contains(7) << endl;

	system("pause");
	return 0;
}
