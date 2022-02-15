#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void v1(fstream& f_in, fstream& f_out, fstream& log)
{
	double a, S = 0, s = 0;
	long long n;
	double arr[2040];

	// get and chek n
	f_in >> n;
	if (n < 0) {
		n = 0;
		log << "number of items has been converted from " << n << " to 0" << endl;
	}
	else if (n > 2040) {
		cout << "the number of elements is too large. 2040 items will be read";
		log << "the number of elements is too large. 2040 items will be read";
		n = 2040;
	}

	//read arr, correct n
	for (int i = 0; i < n; i++) {
		if (f_in.eof()) {
			n = i;
			log << "End of file detected, new value n =" << n << endl;
			break;
		}
		f_in >> a;
		if (a < 0) {
			log << "negative value a = " << a << " on " << i + 1 << " line converted to positive" << endl;
			a = -a;
		}
		arr[i] = a;
		s += pow(a, 0.5);
		S += 1 / s;
	}
	f_out << "actual number of elements: " << n << endl;
	log << n << " numbers read " << endl;

	for (int i = 0; i < n; i++) {
		f_out << arr[i] << " ";
	}
	log << "items written to file " << endl;
	f_out << endl << "S = " << S;
	cout << "S = " << S;
	log << "S value written to file " << endl;

}
