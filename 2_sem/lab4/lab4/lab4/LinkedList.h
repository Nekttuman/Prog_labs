#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
#include <iostream>


template <class T>
class LinkedList {

    struct Node {
        T data;
        Node* next;
    };

    Node* head = nullptr;

public:
    LinkedList(const T* arr, int len);
    LinkedList() {}

  
    void push_back(T data);

    void print(std::fstream& out);
    void print();

    int find(T trgt);

    LinkedList<T>& operator=(const LinkedList<T>& l) {
      while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
      }
      Node* t = l.head;
      while (t != nullptr) {
        this->push_back(t->data);
        t = t->next;
      }

      return *this;
    }

    ~LinkedList();

};


#include "LinkedList.inl"


#endif // !LINKEDLIST
