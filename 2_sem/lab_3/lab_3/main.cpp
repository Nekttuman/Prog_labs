#include <iostream>
#include "Text.h"
#include "Globals.h"


void process(Text& txt) {
	unsigned txt_len = txt.get_count();
	StrL* duplicates = new StrL[txt_len];
	unsigned d_ptr = 0;
	unsigned* d_numbers = new unsigned[txt_len];

	StrL word, new_w;
	bool is_doubles = false;
	for (int i = 0; i < txt_len; i++) {
		word = txt.get_word(i);
		for (int j = 0; j < d_ptr; j++) {
			if (word == duplicates[j]) {
				char one, two, three, four;
				unsigned num = d_numbers[j];
				one = (char)(num / 1000) + 48;
				num %= 1000;
				two = (char)(num / 100) + 48;
				num %= 100;
				three = (char)(num / 10) + 48;
				num %= 10;
				four = (char)(num + 48);
				if (one != '0')
					new_w = StrL(word.get_char(0), '(', one, two,three,four, ')','\0');
				else if (two!='0')
					new_w = StrL(word.get_char(0), '(', two, three, four, ')', '\0');
				else if (three != '0')
					new_w = StrL(word.get_char(0), '(', three, four, ')', '\0');
				else
					new_w = StrL(word.get_char(0), '(', four, ')', '\0');

				txt.set_word(i, new_w);
				is_doubles = true;
				break;
			}
			is_doubles = false;
		}
		if(!is_doubles) {
			duplicates[d_ptr] = word;
			d_numbers[d_ptr] = i+1;
			d_ptr++;
		}
		
	}
}


int main() {
	std::fstream in(INPUT_PATH),
		out(OUTPUT_PATH, std::fstream::trunc | std::fstream::out);
	if (in.is_open() && out.is_open()) {
		Text txt;
		in >> txt;
		process(txt);
		out << txt;
	}
	else {
		std::cout << "files not open";
	}
	in.close(); out.close();
}