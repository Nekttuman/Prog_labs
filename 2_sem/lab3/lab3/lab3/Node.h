#pragma once


template <class T>
class Node {
  T value;
  Node<T>* prev = nullptr, * next = nullptr;

public:
  Node(const T& val, Node <T>* next, Node<T>* prev) : next(next), prev(prev) {
    value = val;
  }

  Node(const T& val) {
    value = val;
  }

  Node() {}

  Node(const T& val, Node<T>* nxt) : next(nxt) {
    value = val;
  }

  ~Node() {
    //delete value;
  }

  

  Node<T>* getNext() { return next; }
  Node<T>* getPrev() { return prev; }
  const T& getValue() { return value; }

  void setValue(const T& val) { 
    delete value;
    value = val; 
  }
  void setNext(Node<T>* nxt) { next = nxt; }
  void setPrev(Node<T>* pre) { prev = pre; }
};