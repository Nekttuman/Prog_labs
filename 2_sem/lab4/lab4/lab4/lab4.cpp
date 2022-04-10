#include <iostream>
#include "LinkedList.h"


int main()
{
	LinkedList<char> l;
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	l.push_back('d');
	l.push_back('e');
	l.push_back('f');

	LinkedList<LinkedList<char>> ll;
	ll.push_back(l);

	
}
