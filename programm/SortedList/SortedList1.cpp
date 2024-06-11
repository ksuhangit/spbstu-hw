#include "SortedList.h"

// ����������� �� ���������
SortedList::SortedList() : head(nullptr) {}

// ����������� �����������
SortedList::SortedList(const SortedList& other) : head(nullptr) {
	copyList(other);
}

// ����������� �����������
SortedList::SortedList(SortedList&& other) noexcept : head(nullptr) {
	moveList(other);
}

// ����������
SortedList::~SortedList() {
	clearList();
}

// �������� ����������� ������������
SortedList& SortedList::operator=(const SortedList& other) {
	if (this != &other) {
		clearList();
		copyList(other);
	}
	return *this;
}

// �������� ������������� ������������
SortedList& SortedList::operator=(SortedList&& other) noexcept {
	if (this != &other) {
		clearList();
		moveList(other);
	}
	return *this;
}

// ����� ��� ���������� ��������
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

// ����� ��� �������� ������� �������� � ������
bool SortedList::contains(int value) const {
	Node* current = head;
	while (current) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

// ����� ��� ����������� ���� �������
SortedList SortedList::merge(const SortedList& other) const {
	SortedList result;
	Node* thisCurrent = head;
	Node* otherCurrent = other.head;

	while (thisCurrent || otherCurrent) {
		if (thisCurrent && (!otherCurrent || thisCurrent->data < otherCurrent->data)) {
			result.add(thisCurrent->data);
			thisCurrent = thisCurrent->next;
		}
		else if (otherCurrent && (!thisCurrent || otherCurrent->data < thisCurrent->data)) {
			result.add(otherCurrent->data);
			otherCurrent = otherCurrent->next;
		}
		else if (thisCurrent && otherCurrent && thisCurrent->data == otherCurrent->data) {
			result.add(thisCurrent->data);
			thisCurrent = thisCurrent->next;
			otherCurrent = otherCurrent->next;
		}
	}

	return result;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const SortedList& list) {
	SortedList::Node* current = list.head;
	while (current) {
		os << current->data << " ";
		current = current->next;
	}
	return os;
}

// ��������� ������ ��� ���������� �������
//����������� ������
void SortedList::copyList(const SortedList& other) {
	if (!other.head) return;

	head = new Node(other.head->data);
	Node* current = head;
	Node* otherCurrent = other.head->next;

	while (otherCurrent) {
		current->next = new Node(otherCurrent->data);
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
}
//����������� ������
void SortedList::moveList(SortedList& other) {
	head = other.head;
	other.head = nullptr;
}
//������� ������
void SortedList::clearList() {
	Node* current = head;
	while (current) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}
