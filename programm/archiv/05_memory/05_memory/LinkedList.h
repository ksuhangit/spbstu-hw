#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Объявление класса Node для элементов связанного списка class Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // Конструктор для узла списка
};

// Объявление класса LinkedList для работы со связанным списком class LinkedList
class LinkedList {
private:
    Node* head; // Указатель на голову списка

public: // Конструкторы, деструктор
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    ~LinkedList();

    // Методы для работы со списком
    void addElement(int val);
    bool contains(int val) const;
    LinkedList combine(const LinkedList& other) const;

    // Перегрузка операторов присваивания
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;

    // Перегрузка оператора вывода для вывода списка в поток
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

#endif // Окончание защиты от множественного включения заголовочного файла