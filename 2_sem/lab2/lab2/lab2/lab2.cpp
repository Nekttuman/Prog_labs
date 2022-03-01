#include <iostream>
#include <fstream>
#include <string>

const int N = 255;
short INPUT_TYPE = 2;


class StrL {
	char s[N];
	short Lenght = 0;

public:
	StrL(){}
	StrL(short L, char*s): Lenght(L) {
		for (int i = 0; i < N; i++) {
			this->s[i] = s[i];
		}
	}
	short getLen() {
		if (Lenght) {
			return Lenght;
		}
		return -1;
	}
	void setLen(short L) {
		if (L > 0) {
			Lenght = L;
		}
	}
	void setString(char *s) {
		for (int i = 0; i < Lenght; i++) {
			this->s[i] = s[i];
		}
	}
	char* getString() {
		return s;
	}

	bool find_repeat_char(char target, short N) {
		if (N > Lenght)
			return false;
		short count = 0;
		for (int i = 0; i < Lenght; i++) {
			if (s[i] == target) {
				count++;
				if (count == N)
					return true;
			}
			else {
				count = 0;
			}
		}
		return false;
	}
	void out_result(std::fstream& out, char t, short N) {
		for (int i = 0; i < Lenght; i++) {
			out << s[i];
		}
		if (this->find_repeat_char(t, N)) {
			
			out << " contains " << t << " " << N << " times.\n";
		}
		else {
			out << " not contains " << t << " " << N << " times.\n";
		}
	}
	};


bool is_correct(std::string tmp) {
	int i = 0;
	if (tmp.empty() || tmp[i] == '\0') {
		return false;
	}
	switch (INPUT_TYPE) {
		{
	case 1: {
		while (tmp[i] == ' ') {
			i++;
		}
		for (int j = 0; j < 2; j++) {
			if (tmp[i] == ' ' || tmp[i] == '\0') {
				return false;
			}
			i++;
		}
		if (tmp[i] < 48 || tmp[i] >= 58 || tmp[i] == '\0') {
			return false;
		}
		i++;
		while (tmp[i] < 48 && tmp[i] >= 58) {
			i++;
		}
		break;
	}
	case 2: {
		while (tmp[i] == ' ') {
			i++;
		}
		i++;
		while (tmp[i] < 58 && tmp[i] >= 48) {
			i++;
		}
		i++;
		if (tmp[i] != ' ' || tmp[i] == '\0') {
			return false;
		}
		while (tmp[i] == ' ') {
			i++;
		}
		if (tmp[i] < 48 || tmp[i] >= 58 || tmp[i] == '\0') {
			return false;
		}
		i++;
		while (tmp[i] < 58 && tmp[i] >= 48) {
			i++;
		}
		if (tmp[i] != ' ' || tmp[i] == '\0') {
			return false;
		}
		break; }
		}
	}

	return true;
}


void process_data(std::fstream& in, std::fstream& out) {
	std::string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		if (is_correct(tmp)) {
			short L;
			char c[N];
			int num = 0;
			char trgt;

			int i = 0;
			switch (INPUT_TYPE)
			{
			case 1: {
				while (tmp[i] == ' ') {
					i++;
				}
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
				L = j - i;
				break; }
			case 2: {
				int len = 0;
				while (tmp[i] == ' ') {
					i++;
				}
				while (tmp[i] >= 48 && tmp[i] < 58) {
					num *= 10;
					num += char(tmp[i]) - 48;
					i++;
				}
				trgt = tmp[i++];
				while (tmp[i] == ' ') {
					i++;
				}
				while (tmp[i] >= 48 && tmp[i] < 58) {
					len *= 10;
					len += char(tmp[i]) - 48;
					i++;
				}
				while (tmp[i] == ' ') {
					i++;
				}
				if (len < 0) {
					len = -len;
				}
				int j = i;
				for (; (j - i < len) && (tmp[j] != '\0') && j < N + i; j++) {
					c[j - i] = tmp[j];
				}
				if (j - i < len) {
					L = j - i;
				}
				else {
					L = len;
				}

				break; }
			}

			StrL line(L,c);
			line.out_result(out, trgt, num);
		}
		else {
			out << "string isn't correct\n";
		}
	}
}


int main()
{
	std::fstream in((INPUT_TYPE == 1) ? "input1.txt" : "input2.txt"),
		out("output.txt", std::fstream::trunc | std::fstream::out);
	if (in.is_open() && out.is_open()) {
		process_data(in, out);
	}
	else {
		std::cout << "files not open";
	}

	in.close(); out.close();
	}

