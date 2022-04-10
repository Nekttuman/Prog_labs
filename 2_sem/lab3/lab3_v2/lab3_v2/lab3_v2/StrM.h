#pragma once
#include <fstream>

const unsigned N = 255;


class StrM {
  char c[N] = "_";
  char Marker = '_';

public:
  StrM(char* c, char m);
  StrM() {}
  friend std::fstream& operator<< (std::fstream& out, const StrM& s);

	  void setM(char m) { Marker = m; }
	  void setData(char* d);

  bool operator==(const StrM& r_s);
};


std::fstream& operator>> (std::fstream& in, StrM& s);