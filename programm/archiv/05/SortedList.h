#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>

class SortedList {
private:
	struct Node {	//���� ������
		int data;
		Node* next;
		Node(int value) : data(value), next(nullptr) {}
	};
	Node* head;
	//����������� ������
	void copyList(const SortedList& other);
	//����������� ������
	void moveList(SortedList& other);
	//������� ������
	void clearList();

public:
	SortedList();
	// ����������� �����������
	SortedList(const SortedList& other);
	// ����������� �����������
	SortedList(SortedList&& other) noexcept;
	//����������
	~SortedList();
	// �������� ����������� ������������
	SortedList& operator=(const SortedList& other);
	// �������� ������������� ������������
	SortedList& operator=(SortedList&& other) noexcept;

	void add(int value);	// ����� ��� ���������� ��������
	bool contains(int value) const;	// ����� ��� �������� ������� �������� � ������
	// ����� ��� ����������� ���� �������
	SortedList merge(const SortedList& other) const;
	//������������� �������� << ��� ������ ���������� � �����.
	friend std::ostream& operator<<(std::ostream& os, const SortedList& list);
	
};

#endif