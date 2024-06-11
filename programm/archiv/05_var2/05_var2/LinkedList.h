#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void insert(T val);
    bool contains(T val);
    LinkedList<T> merge(const LinkedList<T>& list);

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        Node<T>* curr = list.head;
        while (curr != nullptr) {
            os << curr->data << " ";
            curr = curr->next;
        }
        return os;
    }
};

#endif
