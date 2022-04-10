#pragma once

#include <iostream>
#include "Node.h"

template <class T>
class ForwardList {
	Node <T>* head = nullptr;

public:
	using Iterator = Node <T>*;

	ForwardList(Node<T>& hd) :head(&hd) {
		Iterator It = this->head;
		while (It->getNext() != nullptr)
			It = It->getNext();
	}

	ForwardList(){
		T void_data;
		head = new Node<T>(void_data);
	}

	void setHead(Node<T>* hd) {
		head = hd;
	}

	void push(Node<T>& nw) {
		nw.setNext(head);
		head->setPrev(&nw);
		head = &nw;
	}

	void print() {
		Iterator It = head;
		while (It != nullptr) {
			std::cout << It->getValue() << ' ';
			It = It->getNext();
		}
		std::cout << '\n';
	}

	int find(const T& s) {
		int i = 0;
		for (Iterator It = head; It != nullptr; It = It->getNext(), ++i)
			if (It->getValue() == s) return i;
		return -1;
	}

};