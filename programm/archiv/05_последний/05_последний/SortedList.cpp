#include "SortedList.h"

// Конструктор по умолчанию
SortedList::SortedList() : head(nullptr) {}

// Конструктор копирования
SortedList::SortedList(const SortedList& other) : head(nullptr) {
	copyList(other);
}

// Конструктор перемещения
SortedList::SortedList(SortedList&& other) noexcept : head(nullptr) {
	moveList(other);
}

// Деструктор
SortedList::~SortedList() {
	clearList();
}

// Оператор копирующего присваивания
SortedList& SortedList::operator=(const SortedList& other) {
	if (this != &other) {
		SortedList tempSortedList(other);
		std::swap(*this, tempSortedList);
		//clearList();
		//copyList(other);
		return *this;
	}
}

//SortedList& SortedList::operator=(SortedList&& other) noexcept {
//	if (this != &other) {
//		clearList();
//		moveList(other);
//	}
//	return *this;
//}

// Оператор перемещающего присваивания
SortedList& SortedList::operator=(SortedList&& other) noexcept {
	if (this != &other) {
		clearList();
		moveList(other);
	}
	return *this;
}


// Метод для добавления элемента
void SortedList::add(int value) {
	if (contains(value)) {
		return;
	}

	Node* newNode = new Node(value);
	if (!head || head->data > value) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next && current->next->data < value) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

// Метод для проверки наличия элемента в списке
bool SortedList::contains(int value) const {//!! неправилльно, нужно использовать свойство отсортированности
	Node* current = head;
	while (current) {
		if (current->data == value) {
			return true;
		}
		if (current->data > value) {
			return false;
		}

		current = current->next;
	}
	return false;
}

// Метод для объединения двух списков
SortedList SortedList::merge(const SortedList& other) const {
	SortedList result;
	Node** lastPtr = &result.head; // Указатель на указатель, чтобы можно было вставлять новые узлы.

	Node* thisCurrent = head;
	Node* otherCurrent = other.head;

	while (thisCurrent && otherCurrent) {
		if (thisCurrent->data < otherCurrent->data) {
			*lastPtr = new Node(thisCurrent->data);
			thisCurrent = thisCurrent->next;
		}
		else if (otherCurrent->data < thisCurrent->data) {
			*lastPtr = new Node(otherCurrent->data);
			otherCurrent = otherCurrent->next;
		}
		else {
			*lastPtr = new Node(thisCurrent->data);
			thisCurrent = thisCurrent->next;
			otherCurrent = otherCurrent->next;
		}
		lastPtr = &((*lastPtr)->next);
	}

	// Оставшиеся узлы в списке thisCurrent
	while (thisCurrent) {
		*lastPtr = new Node(thisCurrent->data);
		lastPtr = &((*lastPtr)->next);
		thisCurrent = thisCurrent->next;
	}

	// Оставшиеся узлы в списке otherCurrent
	while (otherCurrent) {
		*lastPtr = new Node(otherCurrent->data);
		lastPtr = &((*lastPtr)->next);
		otherCurrent = otherCurrent->next;
	}

	return result;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const SortedList& list) {
	SortedList::Node* current = list.head;
	while (current) {
		os << current->data << " ";
		current = current->next;
	}
	return os;
}

// Приватные методы для управления списком
//Копирование списка
//void SortedList::copyList(const SortedList& other) { // !! переписано, чтобы не было утечек памяти, через std::swap
//	if (!other.head) return;

//	Node* tempList = new Node(other.head->data);
//	Node* current = nullptr;
//	Node* otherCurrent = other.head->next;

//	current = tempList;

//	while (otherCurrent) {
//		current->next = new Node(otherCurrent->data);
//		current = current->next;
//		otherCurrent = otherCurrent->next;
//	}

//	std::swap(head, tempList);

//	Node* tempCurrent = tempList;
//	while (tempCurrent) {
//		Node* next = tempCurrent->next;
//		delete tempCurrent;
//		tempCurrent = next;
//	}
//}


//Копирование списка
void SortedList::copyList(const SortedList& other) {
	clearList();
	if (!other.head)
		return;
	head = new Node(other.head->data);
	Node* current = head;
	Node* src = other.head->next;
	while (src)
	{
		current->next = new Node(src->data);
		current = current->next;
		src = src->next;
	}

}
//Перемещение списка
void SortedList::moveList(SortedList& other) noexcept {
	head = other.head;
	other.head = nullptr;
}
//Очистка списка
void SortedList::clearList() {
	Node* current = head;
	while (current) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}
