#include <iostream>
#include <fstream>
#include "StrM.h"
#include "LinkedList.h"

void process_data(std::fstream& in, std::fstream& out) {
  StrM tmp, trgt;
  in >> trgt;
  LinkedList<StrM> l;
  while (!in.eof()) {
    in >> tmp;
    l.push_back(tmp);
  }
  out << "Linked list data:\n\n";
  l.print(out);
  int res = l.find(trgt);
  out << "\n<<";
  if (res != -1)
    out << trgt << ">> was found in " << res << " position.";
  else
    out << trgt << ">> wasn't found.";
}


void test_dll(std::fstream out);
int main()
{
  std::fstream in("input.txt"),
    out("output.txt", std::fstream::trunc | std::fstream::out);
  if (in.is_open() && out.is_open()) {
    process_data(in, out);
  }
  else {
    std::cout << "files not open";
  }

  in.close(); out.close(); 

  //test_dll();

}

void test_dll(std::fstream out) {
  int a[] = { 1,2,3,4 };
  LinkedList <int> l(a, 4);
  l.print(out);

  l.push_back(3);
  l.print(out);

  int trgt = 3;

  std::cout << l.find(trgt);
}
