#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>

class SortedList {
private:
	struct Node {	//узел списка
		int data;
		Node* next;
		Node(int value) : data(value), next(nullptr) {}
	};
	Node* head;
	//Копирование списка
	void copyList(const SortedList& other);
	//Перемещение списка
	void moveList(SortedList& other);
	//Очистка списка
	void clearList();

public:
	SortedList();
	// Конструктор копирования
	SortedList(const SortedList& other);
	// Конструктор перемещения
	SortedList(SortedList&& other) noexcept;
	//деструктор
	~SortedList();
	// Оператор копирующего присваивания
	SortedList& operator=(const SortedList& other);
	// Оператор перемещающего присваивания
	SortedList& operator=(SortedList&& other) noexcept;

	void add(int value);	// Метод для добавления элемента
	bool contains(int value) const;	// Метод для проверки наличия элемента в списке
	// Метод для объединения двух списков
	SortedList merge(const SortedList& other) const;
	//перегруженный оператор << для вывода информации в поток.
	friend std::ostream& operator<<(std::ostream& os, const SortedList& list);
	
};

#endif