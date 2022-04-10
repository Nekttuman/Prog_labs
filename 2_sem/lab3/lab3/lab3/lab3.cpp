#include <iostream>

#include "StrM.h"
#include "Node.h"
#include "ForwardList.h"
#include <fstream>
#include <string>


using T = StrM;

void process_data(std::fstream& in, std::fstream& out) {
  //in >> target;
  T target;
  in >> target;

  ForwardList <T> lst;
  T tmp;
  while (!in.eof()) {
    in >> tmp;
    //std::cout << tmp<<'\n';
    Node<T> n(tmp);
    lst.push(n);
    lst.print();
  }
  lst.print();
  std::cout << lst.find(target);

}



int main() {


  std::fstream in("input.txt"),
    out("output.txt", std::fstream::trunc | std::fstream::out);
  if (in.is_open() && out.is_open()) {
    process_data(in, out);
  }
  else {
    std::cout << "files not open";
  }

  
  //l.print();
  
}
