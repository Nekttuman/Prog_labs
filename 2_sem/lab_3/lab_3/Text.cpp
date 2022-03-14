#include "Text.h"

std::fstream& operator<<(std::fstream& out, const Text& txt) {
	for (int i = 0; i < txt.get_count(); i++) {
		out << txt.get_word(i)<<" ";
	}
	return out;
}

unsigned get_words_count(std::fstream& in) {
	unsigned w_count = 0;
	char tmp[WORD_LEN];
	while (!in.eof()) {
		in >> tmp;
		w_count++;
	}
	in.seekg(0);
	return w_count;
}

std::fstream& operator>>(std::fstream& in, Text& txt) {
	unsigned w_count = get_words_count(in);
	StrL* words = new StrL[w_count];
	for (int i = 0; i < w_count; i++)
		in >> words[i];

	txt = Text( words, w_count );
	return in;
}

Text::Text(const StrL* s, unsigned count) : words_count(count) {
	for (int i = 0; i < count; i++)
		words[i] = s[i];
}

const StrL& Text::get_word(unsigned n) const {
	return words[n];
}

const unsigned Text::get_count() const {
	return words_count;
}

void Text::set_word(unsigned word_n, StrL s) {
	words[word_n] = s;
}
