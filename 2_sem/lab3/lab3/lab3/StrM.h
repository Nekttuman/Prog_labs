#pragma once
#include <iostream>

class StrM {
  char* d;
  char m;
public:

  StrM(const char* data, char marker);
  StrM() {
    d = new char[0];
    d[0] = '_';
    m = '_';
  }
  StrM(const StrM& s): m(s.m) {
    int count = 0;
    for (const char* c = s.d; *c != s.m; c++)
      count++;
    char* data = new char[count + 1];
    int i = 0;
    for (const char* c = s.d; *c != s.m; c++, ++i)
      data[i] = *c;
    d = data;
    d[count] = s.m;
    m = s.m;
  }

  ~StrM() {
    delete[] d;
  }

  void print();

  const char* getData() const;
  const char getMarker() const { return m; }
  void setData(const char* data, char marker) {
    int count = 0;
    for (const char* c = data; *c != marker; c++)
      count++;
    d = new char[count + 1];
    m = marker;
    for (int i = 0; i < count; i++) {
      d[i] = data[i];
    }
    d[count] = m;
  }


  bool operator ==(const StrM& rStr) const;

  friend std::fstream& operator >>(std::fstream& in, StrM& s);
};

std::ostream& operator <<(std::ostream& out, const StrM &s);