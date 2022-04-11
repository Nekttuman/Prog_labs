//#pragma once
//#include "LinkedList.h"
//#include <fstream>
//
//template <class T>
//class NestedList
//{
//public:
//	struct Node {
//		LinkedList<T>* lst;
//		Node* next;
//	};
//
//private:
//	Node* head = nullptr;
//public:
//	NestedList() {}
//
//
//
//	void push_back(const LinkedList<T>& l) {
//		if (head = nullptr) {
//			head = new Node{ l,nullptr };
//			return;
//		}
//		Node* n = head;
//		while (n->next != nullptr) {
//			n = n->next;
//		}
//		n->next = new Node{ l,nullptr };
//	}
//
//	int getLength() {
//		int res = 0;
//		Node* it = head;
//		while (it != nullptr) {
//			it = it->next;
//			res++;
//		}
//		return res;
//	}
//
//
//	LinkedList<T>& operator[](const int index) {
//		Node* n = head;
//
//		for (int i = 0; i < index; i++)
//			n = n->next;
//
//		return n->lst;
//	}
//
//
//	friend std::fstream& operator >>(std::fstream& in, NestedList<T>& nl);
//
//	friend std::fstream& operator <<(std::fstream& out, NestedList<T>& nl) {
//		Node* n = head;
//		out << "{\n";
//		while (n != nullptr) {
//			n->lst.print();
//			n = n->next;
//		}
//			out << "}";
//
//		return out;
//	}
//
//	
//
//};
//
//template <class T>
//std::fstream& operator >>(std::fstream& in, NestedList<T>& nl) {
//	auto it = head;
//
//	T t;
//	while (!in.eof()) {
//		it = new NestedList<T>::Node{ new LinkedList<T>, nullptr };
//		while (t != '\n')
//		{
//			in >> std::noskipws >> t;
//			if (!it->lst.isIn(t)) {
//				it->lst.pushback(t);
//			}
//			it->lst.sort();
//		}
//
//		it = it->next;
//	}
//	return in;
//}
//
//
