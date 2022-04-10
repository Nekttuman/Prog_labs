#include "StrM.h"
#include <iostream>
#include <string>
#include <fstream>


StrM::StrM(const char* data, char marker) {
  int count = 1;
  for (const char* c = data; *c != marker; c++)
    count++;
  d = new char[count];
  for (int i = 0; i < count; i++)
    d[i] = data[i];
  m = data[count-1];
  d[count-1] = m;
}

void StrM::print() {
  std::cout << "data: ";
  for (char* c = d; *c != m; c++)
    std::cout << *c;
  std::cout << " marker: " << m << '\n';
}

const char* StrM::getData() const {
  return d;
}

bool StrM::operator ==(const StrM& rStr) const {
  if (rStr.m != m) return false;
  for (char* lc = d, *rc = rStr.d;; lc++, rc++) {
    if (*lc != *rc) return false;
    if (*lc == m) return (*rc == m);
  }
}

std::ostream& operator <<(std::ostream& out, const StrM &s) {
  for (const char* d = s.getData(); *d != s.getMarker(); ++d)
    out << *d;
  return out;
}


std::fstream& operator >>(std::fstream& in, StrM& s) {
  std::string line;
  std::getline(in, line);
  if (line.size() == 0) {
    s.setData("_", '_');
  }
  else if (line.size() == 1) {
    s.setData("" + line[0], line[0]);
  }
  else {
    char* data = new char[line.size() - 1];
    for (int i = 1; i < line.size(); i++) {
      data[i - 1] = line[i];
    }

    s.setData(data, line[0]);
    //s.print();
  }

  return in;
}