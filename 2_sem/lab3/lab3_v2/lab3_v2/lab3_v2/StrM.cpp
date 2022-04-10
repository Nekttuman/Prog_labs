#pragma once
#include "StrM.h"
#include <fstream>


StrM::StrM(char* c, char m) {
  this->Marker = m;
  int i = 0;
  for (; i < N && c[i] != m; i++) {
    this->c[i] = c[i];
  }
  this->c[i] = m;
}

void StrM::setData(char* d) {
  int i = 0;
  for (; i < N && d[i] != Marker && d[i] != '\0'; i++) {
    this->c[i] = d[i];
  }
  this->c[i] = Marker;
}

bool StrM::operator==(const StrM& r_s) {
  if (r_s.Marker != Marker)
    return false;
  int i = 0;
  for (; c[i] != Marker && r_s.c[i] != Marker; i++) {
    if (r_s.c[i] != c[i])
      return false;
  }
  return (r_s.c[i] == c[i]);
}


std::fstream& operator>> (std::fstream& in, StrM& s) {
char c[N];
char m;
in >> std::noskipws >> m;
char t = m + 1;
int i = 0;
for (; i < N - 1; i++) {
  in >> t;
  if (t != m && t != '\0')
    c[i] = t;
  else {
    while (t != '\n' && !in.eof())
      in >> t;
    break;
  }
}
c[i] = m;
s.setM(m);
s.setData(c);

return in;
}

std::fstream& operator<< (std::fstream& out, const StrM& s) {
for (int i = 0; s.c[i] != s.Marker; i++) {
  out << s.c[i];
}
out << s.Marker;
return out;
}
