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
    LinkedList(const LinkedList& l);

  
    void push_back(const T& data);

    int find(T trgt);
    int getLen();
    LinkedList<T> getSymmetryDiff(LinkedList<T> l);
    bool isContainedIn(LinkedList<T> l);
    void empty();

    T& operator[](int index) {
      Node* n = head;
      for (int i = 0; i < index; i++) {
        n = n->next;
      }
      return n->data;
    }

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

    friend std::ostream& operator <<(std::ostream& out, const LinkedList<T>& nl) {
        if (nl.head == nullptr) return out;
        auto n = nl.head;
        out << "[";
        for (; n->next != nullptr; n = n->next)
            out << n->data << " ";
        out << n->data << "]";
        return out;
    }

    void getNestedListFromFile(std::fstream& in);

    friend std::fstream& operator <<(std::fstream& out, const LinkedList<T>& nl) {
      if (nl.head == nullptr) return out;
      auto n = nl.head;
      out << "[";
      for (; n->next != nullptr; n = n->next)
        out << n->data << " ";
      out << n->data << "]";
      return out;
    }

    bool operator ==(LinkedList<T> rl) {
      if (this->getLen() != rl.getLen())
        return false;
      Node* rn = rl.head;
      Node* ln = head;
      while (rn != nullptr) {
        if (!(ln->data == rn->data))
          return false;
        rn = rn->next;
        ln = ln->next;
      }
      return true;
    }    

    friend std::istream& operator >>(std::istream& in, LinkedList<T>& l) {
        
        if (l.head != nullptr)
            l.empty();
        T tmp;
        in >> std::noskipws>>tmp;
        while (tmp != '\n') {
            l.push_back(tmp);
            in >> tmp;
        }
        return in;
    }

    friend std::fstream& operator >>(std::fstream& in, LinkedList<T>& l) {

      if (l.head != nullptr)
        l.empty();
      T tmp;
      in >> std::noskipws >> tmp;
      while (tmp != '\n' && !in.eof()) {
        l.push_back(tmp);
        in >> tmp;
      }
      return in;
    }

    ~LinkedList();
};




#include "LinkedList.inl"


#endif // !LINKEDLIST
