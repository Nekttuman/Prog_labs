#include <iostream>
#include "LinkedList.h"
#include "NestedList.h"

#include <fstream>


void process(std::fstream& in1, std::fstream& in2, std::fstream& in3, std::fstream& out) {
  NestedList<char> nl1, nl2, nl3;
  in1 >> nl1;
  in2 >> nl2;
  in3 >> nl3;
  int length = nl1.getLength();
  if (length != nl2.getLenght() || length != nl2.getLength()) {
    std::cout << "length of lists isn't equal";
    return;
  }

  for (int i = 0; i < length; i++) {
    out << i << " " << nl1[i] << ((nl2[i] ^ nl3[i]) == nl1[i] ? " = " : " != ") << nl2[i] << " ^ " << nl3[i]<<"\n";
  }

}

int main()
{
  std::fstream in1("input_l1.txt"), in2("input_l2.txt"), in3("input_l3.txt"),
    out("output.txt", std::fstream::trunc | std::fstream::out);
  if (in1.is_open() && out.is_open() && in2.is_open() && in3.is_open()) {
    process(in1, in2, in3, out);
  }
  else {
    std::cout << "files not open";
  }

  in.close(); out.close();
}
