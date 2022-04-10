#pragma once
#include <fstream>
#include <stdarg.h>
#include "Globals.h"

class StrL
{
	char s[WORD_LEN];
	unsigned len = 0;

public:
	StrL(const char* s, unsigned len);
	explicit StrL(const char ch, ...);
	StrL() { }

	const char* get_s() const { return s; }
	const unsigned get_len() const { return len; }
	void set_word(const char* str);
	void set_len(unsigned n) { len = n; }
	char get_char(unsigned n) const { if (n < len) return s[n]; }
};

std::fstream& operator<<(std::fstream& out, const StrL& s);
std::fstream& operator>>(std::fstream& in, StrL& s);

bool operator == (const StrL& a, const StrL& b);

