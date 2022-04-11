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
    LinkedList(const LinkedList& l) {
        Node* n = l.head;
        while (n != nullptr) {
            this->push_back(n->data);
            n = n->next;
        }
    }

  
    void push_back(const T& data);

    void print(std::fstream& out);
    void print();

    int find(T trgt);
    //bool isInSymmDiff(const LinkedList<char>& l1, const LinkedList<char>& l2);

    void sort() {
    
    }
    bool isIn(T trgt) {

        return false;
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


    //friend std::fstream& operator <<(std::fstream& out, LinkedList<T>& nl);
    friend std::ostream& operator <<(std::ostream& out, LinkedList<T>& nl) {
        if (nl.head == nullptr) return out;
        auto n = nl.head;
        out << "[";
        for (; n->next != nullptr; n = n->next)
            out << n->data << " ";
        out << n->data << "]";
        return out;
    }

    
    friend std::istream& operator >>(std::istream& in, LinkedList<T>& l) {
        
        if (l.head != nullptr)
            l.~LinkedList();
        char tmp;
        in >> std::noskipws>>tmp;
        while (tmp != '\n') {
            l.push_back(tmp);
            in >> tmp;
        }
        return in;
    }

    ~LinkedList();
};

//template <class T>
//std::fstream& operator <<(std::fstream& out, LinkedList<T>& nl) {
//    if (nl.head == nullptr) return out;
//    auto n = nl.head;
//    for (; n->next != nullptr; n = n->next)
//        out << n->data << '\n';
//    out << n->data << '\n';
//}

//template <class T>
//std::ostream& operator <<(std::ostream& out, LinkedList<T>& nl) {
//    if (nl.head == nullptr) return out;
//    auto n = nl.head;
//    for (; n->next != nullptr; n = n->next)
//        out << n->data << '\n';
//    out << n->data << '\n';
//}

#include "LinkedList.inl"


#endif // !LINKEDLIST
