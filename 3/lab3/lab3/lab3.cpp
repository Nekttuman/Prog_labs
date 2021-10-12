/*
Автор: Ищенко Д.О
Группа 1309
Версия: 3.1.1
Дата начала: 10.8.2021
Дата конца: 
Задание:
*/



#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
  double eps, x, a, S;
  fstream f;
  f.open("output.txt", 'w');
  unsigned k = 0;

  cout << "Author: Ishchenko D.O.\n"
       << "Group 1309\n"
       << "Version: 1.1.1\n"
       << "Start date : 10.8.2021\n"
       << "End date : \n"
       << "Exercise: \n\n"; //написать
  f << "Author: Ishchenko D.O.\n"
    << "Group 1309\n"
    << "Version: 1.1.1\n"
    << "Start date : 10.8.2021\n"
    << "End date : \n"
    << "Exercise: \n\n";
  cout << "input x: ";
  f << "input x: ";
  cin >> x; 
  f << x;
  cout << "input epsilon (less than 10^30): ";
  f << "\ninput epsilon (less than 10^30): ";
  cin >> eps;
  f << eps;

  while (fabs(eps) >= 1e30 && k < 2) {
    cout << "Epsilon is incorrect, please enter a number less than 10 ^ 30\nepsilon: ";
    f << "\nEpsilon is incorrect, please enter a number less than 10 ^ 30\nepsilon: ";
    cin >> eps;
    k++;
    f << eps;
  }
  if (eps < 1e30) {
    cout << "epsiln correct!\n";
    f << "\nepsiln correct!\n";
    k = 1; a = 0.125*x; S = a;
    cout << "      k      |      a      |      S      \n";
    f << "      k      |      a      |      S      \n";
    cout << setw(13) << k << "|" << setw(13) << a << "|" << setw(13) << S << endl;
    f << setw(13) << k << "|" << setw(13) << a << "|" << setw(13) << S << endl;
    while (fabs(a) > eps) {
      a *= ((3 * x) / (4 * static_cast<double>(k) + 12));
      S += a;
      k++;
      cout << setw(13) << k << "|" << setw(13) << a << "|" << setw(13) << S << endl;
      f << setw(13) << k << "|" << setw(13) << a << "|" << setw(13) << S << endl;
    }
    cout << a << " <= " << eps << endl;
    cout << a << " is the " << k << " member of the sequence.\n";
    cout << "Answer is " << k;

    f << a << " <= " << eps << endl << a << " is the " << k << " member of the sequence.\n"
      << "Answer is " << k;
    f.close();
  }
  else {
    cout << "The epsilon value is incorrect, your attempts are over! ";
  }
}

