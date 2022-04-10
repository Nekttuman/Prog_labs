#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>


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

  int find(T trgt);

  ~LinkedList();

};


#include "LinkedList.inl"


#endif // !LINKEDLIST
