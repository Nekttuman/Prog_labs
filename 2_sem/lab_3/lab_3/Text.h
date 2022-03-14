#pragma once

#include "StrL.h"

const unsigned WORDS_COUNT = 1024;

class Text
{
	StrL words[WORDS_COUNT];
	unsigned words_count = 0;

public:
	void set_word(unsigned word_n, StrL s);
	
	Text(const StrL* s = nullptr, unsigned count = 0);
	

	const StrL& get_word(unsigned n) const;
	const unsigned get_count() const;
	friend std::fstream& operator>>(std::fstream& in, Text& txt);

};

std::fstream& operator<<(std::fstream& out, const Text& txt);


