#include <iostream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
    Node<T>* next;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename T>
void LinkedList<T>::insert(T val) {
    if (!contains(val)) {
        Node<T>* new_node = new Node<T>(val);
        if (head == nullptr || val < head->data) {
            new_node->next = head;
            head = new_node;
        }
        else {
            Node<T>* curr = head;
            while (curr->next != nullptr && curr->next->data < val) {
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
        }
    }
}

template <typename T>
bool LinkedList<T>::contains(T val) {
    Node<T>* curr = head;
    while (curr != nullptr) {
        if (curr->data == val) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& list) {
    LinkedList<T> result;
    Node<T>* curr1 = head;
    Node<T>* curr2 = list.head;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->data < curr2->data) {
            result.insert(curr1->data);
            curr1 = curr1->next;
        }
        else {
            result.insert(curr2->data);
            curr2 = curr2->next;
        }
    }

    while (curr1 != nullptr) {
        result.insert(curr1->data);
        curr1 = curr1->next;
    }

    while (curr2 != nullptr) {
        result.insert(curr2->data);
        curr2 = curr2->next;
    }

    return result;
}

// Explicit instantiation of the classes
template class Node<int>;
template class LinkedList<int>;
