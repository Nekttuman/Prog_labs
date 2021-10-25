/*
Автор: Ищенко Д.О
Группа 1309
Версия: 2.1.1
Дата начала: 10.8.2021
Дата конца:
Задание: Определить принадлежность точки к области замкнутой с Ох.
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double circle1 (double x, double a, double b, double c);
double line1   (double x, double a, double b, double c);
double line2   (double x, double a, double b, double c);
double circle2 (double x, double a, double b, double c);
double line3   (double x, double a, double b, double c);
double line4   (double x, double a, double b, double c);

int main()
{
  double a, b, c, x, y;

  cout << "Author: Ishchenko D.O.\n"
    << "Group 1309\n"
    << "Version: 2.1.1\n"
    << "Start date : 10.8.2021\n"
    << "End date : \n"
    << "Exercise: determine whether a point belongs to a closed area with the Ox axis \n\n";
  cout << "Input parameters (use a dot as a separator between integer and fractional parts):\na = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c; 
  cout << "Input coordinates:\nx = ";
  cin >> x;
  cout << "y = ";
  cin >> y;

  if (b > 0) {
    if (a == 0) {
      // case1
      if (c <= sqrt(3) * pow(b, 2) - 4 * b) {
        if (x > c && x <= 2 * b) {
          cout << (((y >= line2(x, a, b, c)) && (y <= line1(x, a, b, c))) ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 2 * b && x <= 4 * b) {
          cout << ((y >= line2(x, a, b, c) && (y <= line3(x, a, b, c))) ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 4 * b && x <= 8 * b) {
          cout << ((y >= circle2(x, a, b, c) && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << "Not belongs (False)";
        }
      }
      // case2
      else if (c > sqrt(3) * pow(b, 2) - 4 * b && c <= sqrt(3) * pow(b, 2)) {
        if (x > c && x <= 2 * b) {
          cout << ((0) ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 2 * b && x < 4 * b) {
          cout << (0 ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 4 * b && x <= 8 * b) {
          cout << (0 ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << "Not belongs (False)";
        }
      }
       // case3
      else if (c > sqrt(3) * pow(b, 2) && c <= 2 * b) {
        if (x > c && x <= 2 * b) {
          cout << ((0) ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 2 * b && x < 4 * b) {
          cout << (0 ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (x > 4 * b && x <= 8 * b) {
          cout << (0 ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << "Not belongs (False)";
        }
      }
      // case4
      else if (c > 2 * b && c <= 4 * b) {

      }
      // case 5
      else if (c > 4 * b && c <= sqrt(3) * pow(b, 2) + 4 * b) {

      }
      //case 6
      else if (c > sqrt(3) * pow(b, 2) + 4 * b && c <= 6 * b) {

      }
      //case7
      else if (c > 6 * b) {

      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (a > 0) {

    }
    else {

    }
  }
  else if (b < 0) {
    if (a == 0) {

    }
    else if (a > 0) {

    }
    else {
      cout << "The graph is completely below the axis Ox";
    }
  }
  else {
    cout << ((y == line1(x,a,b,c) && y >= 0 && y <= abs(c)) ? "Belongs (True)" : "Not belongs (False)");
  }

}


double circle1(double x, double a, double b, double c) {
  double y = -sqrt(4 * pow(b, 2) - pow(x, 2)) + b;
  return y;
}

double line1(double x, double a, double b, double c) {
  double y = (x - 2 * b) * (a - b) / (c - 2 * b) + b;
  return y;
}

double line2(double x, double a, double b, double c) {
  double y = (x - c) * (b - abs(2 * b)) / (4 * b - c) + a;
  return y;
}

double circle2(double x, double a, double b, double c) {
  double y = -sqrt(4 * pow(b, 2) - pow((x - 4 * b), 2)) + b;
  return y;
}

double line3(double x, double a, double b, double c) {
  double y = (x - 6 * b) * (a - b) / (c - 2 * b) + b;
  return y;
}

double line4(double x, double a, double b, double c) {
  double y = (x - c - 4 * b) * (b - abs(2 * b)) / (4 * b - c) + a;
  return y;
}
