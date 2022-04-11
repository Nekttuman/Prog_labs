#ifndef LINKEDLIST_INL
#define LINKEDLIST_INL

#include "LinkedList.h"
#include <fstream>

template <class T>
LinkedList<T>::LinkedList(const T* arr, int len) {
    head = new Node{ arr[0], nullptr };
    Node* It = head;
    for (int i = 1; i < len; i++) {
        Node* new_node = new Node{ arr[i], nullptr };
        It->next = new_node;
        It = It->next;
    }
}

template <class T>
void LinkedList<T>::push_back(T data) {
    Node* last = head;
    if (last == nullptr) {
        head = new Node{ data, nullptr };
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = new Node{ data, nullptr };

}

template <class T>
void LinkedList<T>::print(std::fstream& out) {
    if (head == nullptr) return;
    Node* It = head;
    for (; It->next != nullptr; It = It->next)
        out << It->data << '\n';
    out << It->data << '\n';
}


template <class T>
int LinkedList<T>::find(T trgt) {
    Node* It = head;
    int i = 1;
    for (; It->next != nullptr; It = It->next, i++)
        if (It->data == trgt)
            return i;
    if (It->data == trgt)
        return i;
    return -1;
}


template <class T>
LinkedList<T>::~LinkedList() {
    Node* next = head;

    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
}

template <class T>
void LinkedList<T>::print() {
  Node* n = head;
  std::cout << "[";
  while (n != nullptr) {
    std::cout << n->data << " ";
    n = n->next;
  }
  std::cout << "]\n";
}




#endif // !LINKEDLIST