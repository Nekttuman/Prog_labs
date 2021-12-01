/*
Автор: Ищенко Д.О
Группа 1309
Версия: 4.1.1
Дата начала: 1.11.2021
Дата конца:
Задание: You are given a sequence of positive numbers a1, a2,…, an.
Calculate:
		 1        1                      1
S = ___ + _________ + ... + ___________________
		 __    __    __          __    __        __
		Va1   Va1 + Va2         Va1 + Va2 + ... Van
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void v1(fstream& f_in, fstream& f_out, fstream& log);
void v2(fstream& f_in, fstream& f_out, fstream& log);
void print_head(fstream& f_out, int version=0);

int main() {
	string input_path = "../input.txt",
		output_path_v1 = "../output_v1.txt",
		output_path_v2 = "../output_v2.txt",
		log_path = "../log.txt";


	fstream f_in(input_path), 
		f_out(output_path_v1, fstream::trunc | fstream::out),
		log(log_path, fstream::trunc | fstream::out);

	if (!log.is_open()) {
		cout << "log file open eroor";
		return -1;
	}
	if (!f_in.is_open() || !f_out.is_open()) {
		log << "files open error" << endl;
		return -1;
	}

	if (f_in.eof()) {
		cout << "no item count was passed";
		log << "no item count was passed" << endl;
		f_out << "no item count was passed";
		return -1;
	}

	print_head(f_out);

	bool ans = false;
	cout << "Start first version? (1/0) : ";
	cin >> ans;
	if (ans) {
		print_head(f_out, 1);
		v1(f_in, f_out, log);
	}

	cout << "\nStart second version? (1/0) : ";
	cin >> ans;
	if (ans) {
		log.close(); f_in.close(); f_out.close();
		f_in.open(input_path);
		f_out.open(output_path_v2, fstream::trunc | fstream::out);
		log.open(log_path, fstream::trunc | fstream::out);

		print_head(f_out, 2);

		v2(f_in, f_out, log);
	}

	log.close(); f_in.close(); f_out.close();

	return 0;
}

void print_head(fstream &f_out, int version) {
	if (version == 0) {
		cout << "Author: Ishchenko D.O.\n"
			<< "Group 1309\n"
			<< "Version: 4.1.1\n"
			<< "Start date : 1.11.2021\n"
			<< "End date : \n"
			<< "Exercise: You are given a sequence of positive numbers a1, a2,…, an.\n"
			<< "Calculate:\n"
			<< "     1        1                      1\n"
			<< "S = ___ + _________ + ... + ___________________\n"
			<< "     __    __    __          __    __        __\n"
			<< "    Va1   Va1 + Va2         Va1 + Va2 + ... Van\n" << endl;
	}
	else {
		f_out << "Author: Ishchenko D.O.\n"
			<< "Group 1309\n"
			<< "Version: 4.1.1\n"
			<< "Start date : 1.11.2021\n"
			<< "End date : \n"
			<< "Exercise: You are given a sequence of positive numbers a1, a2, . . . , an.\n"
			<< "Calculate:\n"
			<< "     1        1                      1\n"
			<< "S = ___ + _________ + ... + ___________________\n"
			<< "     __    __    __          __    __        __\n"
			<< "    Va1   Va1 + Va2         Va1 + Va2 + ... Van\n";
		cout << "program version: " << version << endl;
		f_out << "program version: " << version << endl;
	}
}