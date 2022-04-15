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
LinkedList<T>::LinkedList(const LinkedList& l) {
  Node* n = l.head;
  while (n != nullptr) {
    this->push_back(n->data);
    n = n->next;
  }
}

template <class T>
void LinkedList<T>::push_back(const T& data) {
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
int LinkedList<T>::getLen() {
  Node* n = head;
  int res = 0;
  while (n != nullptr) {
    res++;
    n = n->next;
  }
  return res;
}

template <class T>
LinkedList<T> LinkedList<T>::getSymmetryDiff(LinkedList<T> l) {
  LinkedList<T> result;

  for (Node* n = head; n != nullptr; n = n->next) {
    if (l.find(n->data) == -1) {
      result.push_back(n->data);
    }
  }
  for (Node* n = l.head; n != nullptr; n = n->next) {
    if (find(n->data) == -1) {
      result.push_back(n->data);
    }
  }
  return result;
}

template<class T>
bool LinkedList<T>::isContainedIn(LinkedList<T> l) {
  Node* n = head;
  while (n != nullptr) {
    if (l.find(n->data) == -1)
      return false;
    n = n->next;
  }

  return true;
}

template <class T>
void LinkedList<T>::empty() {
  Node* next = head;
  while (head != nullptr) {
    next = head->next;
    delete head;
    head = next;
  }
}

template <class T>
void LinkedList<T>::getNestedListFromFile(std::fstream& in) {
  LinkedList<char> tmp;
  while (!in.eof()) {
    in >> tmp;
    this->push_back(tmp);
  }
}


template <class T>
int LinkedList<T>::find(T trgt) {
  if (head == nullptr)
    return -1;
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


#endif // !LINKEDLIST