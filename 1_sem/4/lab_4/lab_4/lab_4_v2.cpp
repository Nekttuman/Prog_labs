#include <iostream>
#include <cmath>
#include <fstream>
#include <numeric>

using namespace std;

void v2(fstream& f_in, fstream& f_out, fstream& log)
{
	double a, S = 0, s = 0;
	long long n;


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
		*(A + i) = a;
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

	delete[] A;
}