/*
Автор: Ищенко Д.О
Группа 1309
Версия: 3.1.1
Дата начала: 10.8.2021
Дата конца: 
Задание: Определить минимальное значение n > 0, для которого 
        очередное слагаемое по модулю не превышает ε > 0 при 
        нахождении результата согласно формуле: 
              n
              _     3ª
              >  ────────  xª
              ─  4ª(a+2)!
             a=1
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void beauty_print(double k, double a, double S, fstream& f);



int main()
{
  double eps, x, a, S;
  fstream f;
  f.open("output.txt", 'w');
  unsigned k = 0;

  cout << "\n\nAuthor: Ishchenko D.O.\n"
    << "Group 1309\n"
    << "Version: 1.1.1\n"
    << "Start date : 10.8.2021\n"
    << "End date : \n"
    << "Exercise: Determine the minimum value n > 0 for which "
    << "\nthe next term does not exceed ε> 0 in absolute value when finding the result"
    << "\naccording to the formula : \n"; 
  char i = 166;
  char d = 196;
  cout << "  n" << endl
    << "  _     3" << i << endl
    << "  >  " << d << d << d << d << d << d << d << d << "  x" << i << endl
    << "  " << d << "  " << 4 << i << "(a+2)!" << endl
    << " a=1\n\n";


  f << "Author: Ishchenko D.O.\n"
    << "Group 1309\n"
    << "Version: 1.1.1\n"
    << "Start date : 10.8.2021\n"
    << "End date : \n"
    << "Exercise: Determine the minimum value n > 0 for which "
    << "\nthe next term does not exceed ε> 0 in absolute value when finding the result"
    << "\naccording to the formula : \n";
  f << "  n" << endl
    << "  _     3ª" << endl
    << "  >  --------  xª" << endl
    << "  -  " << "4ª" << " (a+2)!" << endl
    << " a=1\n\n";

  cout << "input x (use a dot as a separator between integer and fractional parts) : ";
  f << "input x (use a dot as a separator between integer and fractional parts) : ";
  cin >> x; 
  f << x;
  cout << "input epsilon (less than 10^30, also use dot, you can enter a number in exponential\n notation like 1.1e-10): ";
  f << "\ninput epsilon (less than 10^30, also use dot, you can enter a number in exponential\n notation like 1.1e-10): ";
  cin >> eps;
  f << eps;

  while (fabs(eps) >= 1e30 && k < 2 && fabs(eps) >= fabs(x)) {
    cout << "Epsilon is incorrect, please enter a number less than 10 ^ 30 and less than x in absolute value \nepsilon: ";
    f << "\nEpsilon is incorrect, please enter a number less than 10 ^ 30 and less than x in absolute value \nepsilon: ";
    cin >> eps;
    k++;
    f << eps;
  }
  if (fabs(eps) < 1e30) {
    cout << "epsilon correct!\n";
    f << "\nepsilon correct!\n";
    k = 1; a = 0.125*x; S = a;
    cout << "      k      |       a       |      S\n"
      << d << d << d << d << d << d << d << d << d << d << d << d << d << d << d << d
      << d << d << d << d << d << d << d << d << d << d << d << d << d << d << d << d
      << d << d << d << d << d << d << d << d << d << d << d << d << d << endl;
    f << "      k      |       a       |      S\n"
      << "---------------------------------------------\n";

    beauty_print(k, a, S, f);

    bool checkA = 1;
    while (fabs(a) > eps) {
      a *= ((3 * x) / (4 * static_cast<double>(k) + 12));
      S += a;
      k++;
      if (!isinf(a)) {
        beauty_print(k, a, S, f);
      }
      else {
        cout << "a is out of range! Try other values.\n";
        f << "a is out of range! Try other values.\n";
  
        checkA = 0;
        break;
      }
    }

    if (checkA) {
      cout << a << " <= " << eps << endl
        << a << " is the " << k << " member of the sequence.\n"
        << "Answer is " << k;
      f << a << " <= " << eps << endl << a << " is the " << k << " member of the sequence.\n"
        << "Answer is " << k;
    }

    
    f.close();
  }

  else {
    cout << "The epsilon value is incorrect, your attempts are over! ";
  }
}


void beauty_print(double k, double a, double S, fstream& f) {
  if (k < 10) {
    cout << "      " << k << "      |";
    f << "      " << k << "      |";
  }
  else if (k < 100) {
    cout << "     " << k << "      |";
    f << "     " << k << "      |";
  }
  else if (k < 1000) {
    cout << "     " << k << "     |";
    f << "     " << k << "     |";
  }
  else if (k < 10000) {
    cout << "    " << k << "     |";
    f << "    " << k << "     |";
  }
  cout << scientific << setw(14)<< a << " | " << S << '\n'<<resetiosflags(ios_base::floatfield);
  f << scientific << setw(14)<< a << " | " << S << '\n'<<resetiosflags(ios_base::floatfield);
}
