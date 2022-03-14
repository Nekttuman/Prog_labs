#include "StrL.h"
#include <iostream>


std::fstream& operator<<(std::fstream& out, const StrL& s) {
	const char* word = s.get_s();
	for (int i = 0; i < s.get_len(); i++) {
		out.put(word[i]);
	}
	return out;
}
void StrL::set_word(const char* str) {
	for (int i = 0; i < WORD_LEN; i++)
		s[i] = str[i];
}

std::fstream& operator>>(std::fstream& in, StrL& s) {
	char word[WORD_LEN];
	in >> word;
	s.set_word(word);

	char t = word[0]; unsigned count = 0;
	while (t != '\0') {
		count++;
		t = word[count];
	}
	s.set_len(count);

	return in;
}



bool operator == (const StrL& a, const StrL& b) {
	if (a.get_len() != b.get_len())
		return false;
	for (int i = 0; i < a.get_len(); i++) {
		if (a.get_char(i) != b.get_char(i))
			return false;
	}
	return true;
}

