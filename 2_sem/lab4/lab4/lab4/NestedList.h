#pragma once
#include "LinkedList.h"
#include <fstream>

template <class T>
class NestedList
{
	struct Node{
		LinkedList<T> data;
		Node* next;
	}
	Node* head = nullptr;
public:
	NestedList() {}

	void push_back(const LinkedList<T>& l) {
		if (head = nullptr) {
			head = new Node{ l,nullptr };
			return;
		}
		Node* n = head;
		while (n->next != nullptr) {
			n = n->nullptr;
		}
		n->next = new Node{ l,nullptr };
	}

	std::fstream& operator >>(std::fstream& in, NestedList& nl) {

	}



};

