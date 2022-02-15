#include <iostream>
#include <string>
#include <fstream>

const int N = 255;
short INPUT_TYPE = 1;

struct SuperString {
	char c[N];
	char Marker;
		
	SuperString(char* c, char m) {
		this->Marker = m;
		for (int i = 0; i < N; i++) {
			this->c[i] = c[i];
		}
	}

	bool find_repeat_char(int num, char ch);
	void out_result(std::fstream &out, bool is_contain, int num, char trgt);
};


bool is_correct(std::string tmp) {
	if (tmp.empty()) {
		return false;
	}
	int i = 0;
	while (tmp[i] == ' ') {
		i++;
	}
	for (int j = 0; j < 3; j++) {
		if (tmp[i] == ' ' || tmp[i] == '\0') {
			return false;
		}
		i++;
	}
	if (tmp[i] < 48 || tmp[i] >= 58 || tmp[i]=='\0') {
		return false;
	}
	i++;
	while (tmp[i] < 48 && tmp[i] >= 58) {
		i++;
	}
	while (tmp[i] == ' ') {
		i++;
	}
	return true;
}



void process_data(std::fstream &in, std::fstream &out) {
	// считывает построчно данные отправляет на проверку в is_correct()
	// если это так, то вызывает метод find_repeat_char и результат отправляет в 
	// out_result
	std::string tmp;
	std::string s;
	while (!in.eof()) {
		getline(in, tmp);
		if (is_correct(tmp)) {
			char Marker;
			char c[N];
			int num = 0;
			char trgt;
			switch (INPUT_TYPE)
			{
			case 1: {
				int i = 0;
				while (tmp[i] == ' ') {
					i++;
				}
				Marker = tmp[i++];
				char stop_sign = tmp[i++];
				trgt = tmp[i++];
				while (tmp[i] >= 48 && tmp[i] < 58) {
					num *= 10;
					num += char(tmp[i]) - 48;
					i++;
				}

				while (tmp[i] == ' ') {
					i++;
				}
				int j = i;
				for (; (tmp[j] != stop_sign) && (tmp[j] != '\0') && j < N + i; j++) {
					c[j - i] = tmp[j];
				}
				c[j-i] = Marker;
				break;}
			case 2: {

				break;}
			}

			SuperString line (c, Marker);
			line.out_result(out, line.find_repeat_char(num, trgt), num, trgt);
		}
		else {
			out << "string isn't correct\n";
		}
	}	
}


int main() {
	std::fstream in("input.txt"), out("output.txt", std::fstream::trunc | std::fstream::out);
	if (in.is_open() && out.is_open()) {
		process_data(in, out);
	}
	else {
		std::cout << "files not open";
	}
	
	in.close();
}

bool SuperString::find_repeat_char(int num, char ch) {
	unsigned count = 0, i = 0;
	while (c[i] != Marker) {
		if (c[i] == ch) {
			++count;
			if (count >= num)
				return true;
		}
		else {
			count = 0;
		}
		i++;
	}
	return false;
}

void SuperString::out_result(std::fstream &out, bool is_contain, int num, char trgt) {
	out << "\'";
	for (int i = 0; c[i] != Marker; i++) {
		out << c[i];
	}
	out << '\'' << (is_contain ? " contains \'" : " does not contain \'")
		<< trgt << "\' " << std::to_string(num) << " times. \n";
}
