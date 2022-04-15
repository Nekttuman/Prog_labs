#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
#include <iostream>

const int ITEM_LENGTH = 5;


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


    void push_back(T data);

    int find(T trgt);
    int getLen();
    LinkedList<T> getSymmetryDiff(LinkedList<T> l);
    bool isContainedIn(LinkedList<T> l);
    void empty();

    bool isContainedInSymmDiff(LinkedList<T> l1, LinkedList<T> l2) {
        Node* n1 = head, * n2 = l1.head, * n3 = l2.head;
        for (; n1 != nullptr; n1 = n1->next) {
            while (n2 != nullptr && n2->data < n1->data)
                n2 = n2->next;
            while (n3 != nullptr && n3->data < n1->data)
                n3 = n3->next;

            if (n2 == nullptr) {
                if (n3 == nullptr)
                    return false;
                else if (n1->data != n3->data)
                    return false;
                else
                    continue;
            }
            else if (n3 == nullptr) {
                if (n2 == nullptr)
                    return false;
                else if (n1->data != n2->data)
                    return false;
                else
                    continue;
            }

            if ((n1->data == n2->data && n1->data == n3->data) ||
                (n1->data != n2->data && n1->data != n3->data))
                return false;
        }
        return true;
    }

    bool operator <(LinkedList<T> l) {
        Node* n = head; Node* rn = l.head;
        for (; rn != nullptr && n != nullptr; rn = rn->next, n = n->next) {
            for (int i = 0; i < ITEM_LENGTH; i++) {
                if ((n->data)[i] == (rn->data)[i])
                    continue;
                else
                    return ((n->data)[i] < (rn->data)[i]);
            }
        }
        if (rn != nullptr && n == nullptr)
            return true;
        return false;
    }

    bool operator >(LinkedList <T> l) {
        Node* n = head; Node* rn = l.head;
        for (; rn != nullptr && n != nullptr; rn = rn->next, n = n->next) {
            for (int i = 0; i < ITEM_LENGTH; i++) {
                if ((n->data)[i] == (rn->data)[i])
                    continue;
                else
                    return ((n->data)[i] > (rn->data)[i]);

            }
        }
        if (rn == nullptr && n != nullptr)
            return false;
        return true;
    }

    bool operator ==(LinkedList<T> l) {
        Node* n = head; Node* rn = l.head;
        for (; rn != nullptr && n != nullptr; rn = rn->next, n = n->next) {
            for (int i = 0; i < ITEM_LENGTH; i++) {
                if ((n->data)[i] != (rn->data)[i])
                    return false;
            }
        }
        if (rn != nullptr || n != nullptr)
            return false;
        return true;
    }

    bool operator !=(LinkedList<T> l) {
        Node* n = head; Node* rn = l.head;
        for (; rn != nullptr && n != nullptr; rn = rn->next, n = n->next) {
            for (int i = 0; i < ITEM_LENGTH; i++) {
                if ((n->data)[i] != (rn->data)[i])
                    return true;
            }
        }
        if (rn != nullptr || n != nullptr)
            return true;
        return false;
    }


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

    void getNestedListFromFile(std::fstream& in) {

        while (!in.eof()) {
            LinkedList<char*> line;
            char* item = new char[ITEM_LENGTH];
            char tmp = ' ';
            for (int i = 0; tmp != '\n'; i++) {
                in >> std::noskipws>>tmp;
                item[i] = tmp;


                if (i == ITEM_LENGTH-1) {
                    if (tmp == '\n')
                        item[i] = ' ';
                    i = -1;
                    line.push_back(item);
                    item = new char[ITEM_LENGTH];
                }
                else if (tmp == '\n' || in.eof()) {
                    for (int j = i; j < ITEM_LENGTH; j++)
                        item[j] = ' ';
                    if (i!=0)
                        line.push_back(item);
                    break;
                }
            }
            this->push_back(line);
        }
    }


    void stypidPrint() {
        for (Node* n = head; n != nullptr; n = n->next)
            (n->data).superStupidPrint();
    }
    std::fstream& stypidPrint(std::fstream &out) {
        for (Node* n = head; n != nullptr; n = n->next)
            (n->data).superStupidPrint(out);
        return out;
    }

    void superStupidPrint() {
        std::cout << "{ ";
        for (Node* n = head; n != nullptr; n = n->next) {
            char *p = (n->data);
            for (int i = 0; i < ITEM_LENGTH; i++, p++) {
                std::cout << *p;
            }
            std::cout << " ";
        }
        std::cout << " }";
        std::cout << '\n';
    }

    std::fstream& superStupidPrint(std::fstream &out) {
        out << "{ ";
        for (Node* n = head; n != nullptr; n = n->next) {
            char* p = (n->data);
            for (int i = 0; i < ITEM_LENGTH; i++, p++) {
                out << *p;
            }
            out << " ";
        }
        out << " }";
        out << '\n';
        return out;
    }

    friend std::fstream& operator <<(std::fstream& out, const LinkedList<T>& nl) {
      if (nl.head == nullptr) return out;
      auto n = nl.head;
      out << "[";
      for (; n->next != nullptr; n = n->next)
        out << n->data << " ";
      out << n->data << "]";
      return out;
    }

    /*bool operator ==(LinkedList<T> rl) {
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
    } */   

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
