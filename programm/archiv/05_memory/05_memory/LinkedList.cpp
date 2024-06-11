#include "LinkedList.h"

// Конструктор по умолчанию инициализирует голову списка как nullptr
LinkedList::LinkedList() : head(nullptr) {} 

// Конструктор копирования создает копию переданного списка
LinkedList::LinkedList(const LinkedList& other) {
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }

    Node* temp = other.head;
    head = new Node(temp->data);
    Node* curr = head;
    temp = temp->next;

    while (temp != nullptr) {
        curr->next = new Node(temp->data);
        curr = curr->next;
        temp = temp->next;
    }
}

// Конструктор перемещения указывает указателю на голову у другого списка и обнуляет его голову 
LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}
// Деструктор освобождает память, выделенную под узлы списка
LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
// Метод addElement добавляет элемент в упорядоченном виде, если его нет в списке
void LinkedList::addElement(int val) {
    if (contains(val)) {
        return;
    }

    Node* newElement = new Node(val);

    if (head == nullptr || val < head->data) {
        newElement->next = head;
        head = newElement;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data < val) {
        curr = curr->next;
    }

    newElement->next = curr->next;
    curr->next = newElement;
}
// Метод contains проверяет, содержится ли элемент в списке bool
bool LinkedList::contains(int val) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == val) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
// Метод combine объединяет два списка, создавая новый LinkedList
LinkedList LinkedList::combine(const LinkedList& other) const {
    LinkedList result(*this);

    Node* temp = other.head;
    while (temp != nullptr) {
        result.addElement(temp->data);
        temp = temp->next;
    }

    return result;
}
// Оператор присваивания копированием
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }

    LinkedList temp(other);
    std::swap(head, temp.head);

    return *this;
}
// Оператор присваивания перемещением
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    Node* temp = head;
    head = other.head;
    other.head = temp;

    return *this;
}
// Перегрузка оператора вывода для удобного вывода списка в поток
std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* curr = list.head;
    while (curr != nullptr) {
        os << curr->data << " ";
        curr = curr->next;
    }
    return os;
}