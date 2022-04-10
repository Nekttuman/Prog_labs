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
}
