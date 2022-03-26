#pragma once

#include "StrL.h"
#include "Globals.h"


class Text
{
	StrL words[WORDS_COUNT];
	unsigned words_count = 0;
	StrL ws[WORDS_COUNT + 1];

public:
	void set_word(unsigned word_n, StrL s);
	
	Text(const StrL* s = nullptr, unsigned count = 0, const StrL* ws_ = nullptr);

	const StrL& get_word(unsigned n) const;
	const unsigned get_count() const;
	const StrL& get_ws(unsigned n) const;


	friend std::fstream& operator>>(std::fstream& in, Text& txt);
};

std::fstream& operator<<(std::fstream& out, const Text& txt);


