#include <iostream>
#include "LinkedList.h"
#include "NestedList.h"

#include <fstream>


//void process(std::fstream& in1, std::fstream& in2, std::fstream& in3, std::fstream& out) {
//  NestedList<char> nl1, nl2, nl3;
//  in1 >> nl1;
//  in2 >> nl2;
//  in3 >> nl3;
//  int length = nl1.getLength();
//  if (length != nl2.getLength() || length != nl2.getLength()) {
//    std::cout << "length of lists isn't equal";
//    return;
//  }
//
//  for (int i = 0; i < length; i++) {
//      out << i << " ";
//      out << nl1[i] << (nl1[i].isInSymmDiff(nl2[i], nl3[i]) ? " ⊂ " : " !⊂ ");
//      out << nl2[i] << " ^ ";
//      out << nl3[i] << "\n";
//  }
//}


void process(LinkedList<LinkedList<char>> nl1, LinkedList<LinkedList<char>> nl2, LinkedList<LinkedList<char>> nl3, std::fstream& out) {
  int l_len = nl1.getLen();
  if (l_len != nl2.getLen() || l_len != nl3.getLen()) {
    std::cout << "Error: nested list are not equal by length\n";
    return;
  }

  for (int i = 0; i < l_len; i++) {
    out << nl1[i];
    out << ((nl1[i].isContainedIn(nl2[i].getSymmetryDiff(nl3[i]))) ? " is contained in symmetry difference of " : " is not contained in symmetry difference of ");
    out << nl2[i] <<" and ";
    out << nl3[i]<<'\n';
  }

  out << "\n\nNested List 1:\n" << nl1<<"\n";
  out << "Nested List 2:\n" << nl2 << "\n";
  out << "Nested List 3:\n" << nl3 << "\n";

}



void test();


int main()
{
  std::fstream in1("input_l1.txt"), in2("input_l2.txt"), in3("input_l3.txt"),
    out("output.txt", std::fstream::trunc | std::fstream::out);
  if (in1.is_open() && out.is_open() && in2.is_open() && in3.is_open()) {
    LinkedList<LinkedList<char>> nl1, nl2, nl3;
    nl1.getNestedListFromFile(in1); nl2.getNestedListFromFile(in2); nl3.getNestedListFromFile(in3);
    process(nl1,nl2,nl3, out);
  }
  else {
    std::cout << "files not open";
  }

  in1.close(); in2.close(); in3.close(); out.close();
  //test();
}













void test() {
  LinkedList<LinkedList<LinkedList<char>>> l3;

  LinkedList<LinkedList<char>> l2;

  LinkedList<char> l1;
  l1.push_back('1');

  l2.push_back(l1);

  l3.push_back(l2);

  l3[0][0].push_back('2');
  l3[0][0].push_back('3');
  l3[0][0].push_back('4');

  l2[0].push_back('11');
  l3.push_back(l2);

  std::cout << l3;
}