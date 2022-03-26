#include "Text.h"

Text::Text(const StrL* s, unsigned count, const StrL* ws_) : words_count(count) {
	for (int i = 0; i < count; i++)
		words[i] = s[i];
	for (int i = 0; i < count+1; i++)
		if (count !=0)
			ws[i] = ws_[i];
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

const StrL& Text::get_ws(unsigned n) const {
	return ws[n];
}


std::fstream& operator<<(std::fstream& out, const Text& txt) {
	for (int i = 0; i < txt.get_count(); i++)	{
		out << txt.get_ws(i) << txt.get_word(i);
	}
	out << txt.get_ws(txt.get_count());
	return out;
}

unsigned get_words_count(std::fstream& in) {
	unsigned w_count = 0;
	char tmp[WORD_LEN];
	while (!in.eof()) {
		in >> tmp;
		if (tmp != "\n" && tmp != "\0" && strlen(tmp) != 0) {
			w_count++;
		}
	}
	in.close();
	in.open(INPUT_PATH);
	return w_count;
}


bool is_sep(char ch) {
	for (int i = 0;i<sizeof(SEPARATORS)/sizeof(char); i++)
	{
		if (ch == SEPARATORS[i])
			return true;
	}
	return false;
}


std::fstream& operator>>(std::fstream& in, Text& txt) {
	
	unsigned w_count = get_words_count(in);
	StrL* words = new StrL[w_count];
	StrL* ws = new StrL[w_count + 1];

	unsigned ws_ptr = 0, words_ptr = 0, w_ptr = 0;
	char t; 
	char* tmp = new char[WORD_LEN]; bool is_ws = true;
	t = in.get();
	while (!in.eof()) {
		while (is_sep(t) && !in.eof()) {
			if (!is_ws) {
				words[words_ptr] = StrL(tmp, w_ptr);
				words_ptr++;
				w_ptr = 0;
			}
			is_ws = true;
			tmp[w_ptr] = t;
			w_ptr++;
			t = in.get();
		}
		while (!is_sep(t) && !in.eof()) {
			if (is_ws) {
				ws[ws_ptr] = StrL(tmp, w_ptr);
				ws_ptr++;
				w_ptr = 0;
				is_ws = false;
			}
			tmp[w_ptr] = t;
			w_ptr++;
			t = in.get();
		}
		if (in.eof()) {
			if (is_ws) {
				ws[ws_ptr] = StrL(tmp, w_ptr);
			}
			else {
				words[words_ptr] = StrL(tmp, w_ptr);
			}
		}
	}
	txt = Text( words, w_count, ws);


	return in;
}

