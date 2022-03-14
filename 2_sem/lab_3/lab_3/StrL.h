#pragma once
#include <fstream>
#include <stdarg.h>

const unsigned WORD_LEN = 32;

class StrL
{
	char s[WORD_LEN];
	unsigned len = 0;

public:
	StrL(const char* s, unsigned len) : len(len) {
		for (int i = 0; i < len; i++) {
			this->s[i] = s[i];
		}
	}
	StrL(const char ch, ...) {
		len++;
		s[0] = ch;
		va_list list;
		va_start(list, ch);
		while (true) {
			char t = va_arg(list, char);
			if (t == '\0')
				break;
			s[len] = t;
			len++;
		}
		va_end(list);
	}
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

