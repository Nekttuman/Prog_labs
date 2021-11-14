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
#include <cmath>
#include <fstream>
#include <numeric>

using namespace std;

int main2()
{
	fstream f_in("../test_in.txt"), //"../test_in.txt"
		f_out("../output.txt", fstream::trunc | fstream::out),
		log("../log.txt", fstream::trunc | fstream::out);
	double a, S = 0, s = 0;
	long long n;


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
	f_out << "Author: Ishchenko D.O.\n"
		<< "Group 1309\n"
		<< "Version: 4.1.1\n"
		<< "Start date : 1.11.2021\n"
		<< "End date : \n"
		<< "Exercise: You are given a sequence of positive numbers a1, a2,…, an.\n"
		<< "Calculate:\n"
		<< "     1        1                      1\n"
		<< "S = ___ + _________ + ... + ___________________\n"
		<< "     __    __    __          __    __        __\n"
		<< "    Va1   Va1 + Va2         Va1 + Va2 + ... Van" << endl;
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

	// Get n
	f_in >> n;
	if (n < 0) {
		n = 0;
		log << "number of items has been converted from " << n << " to 0" << endl;
	}
	for (int i = 0; i < n; i++) {
		if (f_in.eof()) {
			n = i;
			log << "End of file detected, new value n =" << n << endl;
			break;
		}
		f_in >> a;
	}
	f_in.seekg(std::ios::beg);
	f_in >> a; // move pointer first a (a = n now)
	f_out << "actual number of elements: " << n << endl;

	// define A items
	double* A = new double[n];
	for (int i = 0; i < n; i++) {
		f_in >> a;
		if (a < 0) {
			log << "negative value a = " << a << " on " << i + 1 << " line converted to positive" << endl;
			a = -a;
		}
		*(A+i) = a;
		f_out << a << " ";
	}
	log << n << " numbers read " << endl;
	log << "Numbers written to file " << endl;



	// calculate S
	for (int i = 0; i < n; i++) {
		s += sqrt(*(A + i));
		S += (1 / s);
	}

	cout << "S = " << S;
	f_out << endl << "S = " << S;
	log << "S value written to file " << endl;

	log.close(); f_in.close(); f_out.close();
	delete[] A;

	return 0;
}
