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
#include <string>

using namespace std;

double circle1 (double x, double a, double b, double c);
double line1   (double x, double a, double b, double c);
double line2   (double x, double a, double b, double c);
double circle2 (double x, double a, double b, double c);
double line3   (double x, double a, double b, double c);
double line4   (double x, double a, double b, double c);

int main(int argc, char* argv[])
{
  double a, b, c, x, y;
  if (argc > 1) {
    a = stod(argv[1]);
    b = stod(argv[2]);
    c = stod(argv[3]);
    x = stod(argv[4]);
    y = stod(argv[5]);
  }
  else {
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
  }

  if (b < 0) {
    x = -x;
    y = -y;

    a = -a; b = -b; c = -c;
  }
  else if (b == 0) {
    cout << ((y == line1(x, a, b, c) && y >= 0 && y <= abs(c)) ? "Belongs (True)" : "Not belongs (False)");
  }


  if (a == 0) {
    // case1
    if (c <= sqrt(3) * pow(b, 2) - 4 * b) {
      if (x >= c && x <= 2 * b) {
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
        if (y > 0) {
          cout << ((y >= circle1(x, a, b, c) && y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y >= circle1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > 2 * b && x < 4 * b) {
        cout << ((y > line2(x, a, b, c && y <= 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= 8 * b) {
        cout << ((y >= circle2(x, a, b, c) && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    // case3
    else if (c > sqrt(3) * pow(b, 2) && c <= 4 * b) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y >= 0 && y <= circle1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= c) {
        cout << ((y >= 0 && y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > c && x <= 4 * b) {
        cout << ((y >= line2(x, a, b, c) && y <= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= 6 * b) {
        cout << ((y >= line2(x, a, b, c) && y <= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 6 * b && x <= 8 * b) {
        cout << ((y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    // case4
    else if (c > 4 * b && c <= sqrt(3) * pow(b, 2) + 4 * b) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y >= 0 && y <= circle1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= c) {
        if (y >= 0) {
          cout << ((y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y >= circle2(x, a, b, c) && y <= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > c && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << ((y <= 0 && y >= circle2(x, a, b, c) && y <= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x < c + 4 * b) {
        cout << ((y >= 0 && y <= circle2(x, a, b, c) && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    //case 5
    else if (c > sqrt(3) * pow(b, 2) + 4 * b) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y >= 0 && y <= circle1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= c) {
        if (y >= 0) {
          cout << ((y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y >= circle2(x, a, b, c) && y <= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x >= sqrt(3) * pow(b, 2) + 4 * b && x <= c + 4 * b) {
        cout << ((y >= 0 && y <= circle2(x, a, b, c) && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else {
      cout << "Not belongs (False)";
    }
  }
  else if (a < 0) {
    double tmp1 = (-b) * (c - 2 * b) / (a - b) + 6 * b;
    if (c <= 2 * b) {
      if (x >= c && x <= sqrt(3) * pow(b, 2)) {
        if (y >= 0) {
          cout << ((y <= line1(x, a, b, c) && y >= circle1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y >= line2(x, a, b, c) && y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > sqrt(3) * pow(b, 2) && x <= 4 * b) {
        if (y == 0) {
          cout << "Belongs (True)";
        }
        else if (y < 0) {
          cout << ((y >= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        if (y >= 0) {
          cout << ((y <= line3(x, a, b, c) && y >= circle2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y >= circle2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 6 * b) {
        cout << ((y <= circle2(x, a, b, c) && y >= 0 && y >= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (c > 2 * b && c <= 4 * b) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y <= circle1(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= 4 * b) {
        if (y == 0) {
          cout << "Belongs (True)";
        }
        else if (y < 0) {
          cout << ((y >= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y <= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << ((y <= 0 && y >= circle2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 6 * b) {
        cout << ((y <= circle2(x, a, b, c) && y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (c > 4 * b) {
      if (y > 0) {
        cout << (((y <= line1(x, a, b, c) && y <= circle1(x, a, b, c)) ||
          (y <= line3(x, a, b, c) && y <= circle2(x, a, b, c))) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (y < 0) {
        if (x <= sqrt(3) * pow(b, 2) + 4 * b) {
          cout << ((y >= circle2(x, a, b, c) && x >= line1(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << ((y <= line3(x, a, b, c) && x >= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
      }
      else {
        cout << ((x >= sqrt(3) * pow(b, 2) && x <= tmp1) ? "Belongs (True)" : "Not belongs (False)");
      }
    }
    else {
      cout << "Not belongs (False)";
    }
  }
  else { // a>0
    if (c <= 0) {
      if (x <= 0 && x >= c) {
        cout << (((y <= line1(x, a, b, c) && y >= line2(x, a, b, c)) ||
          (y <= line3(x, a, b, c) && y >= line4(x, a, b, c))) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 0 && x < sqrt(3) * pow(b, 2)) {
        cout << (((y <= line1(x, a, b, c) && y >= circle2(x, a, b, c) && y >= line2(x, a, b, c)) ||
          (y <= circle1(x, a, b, c) && y <= line2(x, a, b, c) && y >= 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x >= sqrt(3) * pow(b, 2) && x <= 4 * b) {
        cout << (((y >= line2(x, a, b, c) && y <= 0) ||
          (y <= line3(x, a, b, c) && y >= line4(x, a, b, c)) ||
          (y <= line2(x, a, b, c) && y >= 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << (((y >= circle2(x, a, b, c) && y <= 0) ||
          (y <= line3(x, a, b, c) && y >= line4(x, a, b, c) && y >= 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 4 * b) {
        cout << ((y >= 0 && y <= circle2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= 8 * b) {
        //

        cout << ((y >= 0 && y <= line4(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 8 * b && x <= c + 4 * b) {
        cout << ((y <= line4(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (c > 0 && c <= 2 * b) {
      if (x >= 0 && x <= sqrt(3) * pow(b, 2)) {
        cout << (((y >= line2(x, a, b, c) && y >= circle1(x, a, b, c) && y <= line1(x, a, b, c)) ||
          (y >= line1(x, a, b, c) && y <= line2(x, a, b, c))) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << (((y >= line2(x, a, b, c) && y < 0) ||
          (y <= circle1(x, a, b, c) && y > 0 && y<=line2(x,a,b,c)) ||
          (y == 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= 4 * b) {
        cout << ((y <= line2(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << (((y <= line2(x, a, b, c) && y > 0) ||
          (y >= line2(x, a, b, c) && y >= circle2(x, a, b, c) && y < 0) ||
          (y == 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 6 * b) {
        cout << ((y <= circle2(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 6 * b && x <= 8 * b) {
        cout << ((y <= line4(x, a, b, c) && y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }

    }
    else if (c > 2 * b && c <= b * 4) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y >= 0 && y <= circle2(x,a,b,c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= 4 * b) {
        cout << ((y <= line2(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << (((y >= circle2(x, a, b, c) && y <= 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 6 * b) {
        cout << ((y <= circle2(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 6 * b && x <= 8 * b) {
        cout << ((y <= line4(x, a, b, c) && y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (c > 4 * b && c< a + 5*b) {
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y <= circle1(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= 4 * b) {
        cout << ((y <= line1(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x <= sqrt(3) * pow(b, 2) + 4 * b) {
        cout << (((y <= line1(x, a, b, c) && y > 0 && y >= line2(x, a, b, c)) ||
          (y <= line2(x, a, b, c) && y >= circle2(x, a, b, c) && y < 0) ||
          (y == 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > sqrt(3) * pow(b, 2) + 4 * b && x <= 6 * b) {
        cout << ((y <= circle2(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 6 * b && x <= c + 4 * b) {
        cout << ((y >= line4(x, a, b, c) && y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else if (c >= a + 5 * b) {
    double tmp2 = (-a) * (4 * b - c) / (-a - b) + c;
      if (x >= sqrt(3) * pow(b, 2) && x <= 2 * b) {
        cout << ((y <= circle1(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 2 * b && x <= 4 * b) {
        cout << ((y <= line1(x, a, b, c) && y >= 0) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x > 4 * b && x < tmp2) {
        cout << (((y <= line1(x, a, b, c) && y > 0 && y >= line2(x, a, b, c)) ||
          (y <= line2(x, a, b, c) && y >= circle2(x, a, b, c) && y < 0) ||
          (y == 0)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else if (x >= tmp2 && x <= 6 * b) {
        if (y > 0) {
          cout << ((y <= line2(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else if (y == 0) {
          cout << "Belongs( True)";
        }
        else if (y < 0) {
          cout << ((y >= circle2(x, a, b, c) && y <= line2(x,a,b,c)) ? "Belongs (True)" : "Not belongs (False)");
        }
        else {
          cout << "Not belongs (False)";
        }
      }
      else if (x > 6 * b && x <= c + 4 * b) {
        cout << ((y >= line4(x, a, b, c) && y >= 0 && y <= line3(x, a, b, c)) ? "Belongs (True)" : "Not belongs (False)");
      }
      else {
        cout << "Not belongs (False)";
      }
    }
    else {
      cout << "Not belongs (False)";
    }
  }
}

double circle1(double x, double a, double b, double c) {
  double y = -sqrt(4 * pow(b, 2) - pow(x, 2)) + b;
  return y;
}
double line1(double x, double a, double b, double c) {
  if (c != 2 * b) {
    double y = (x - 2 * b) * (a - b) / (c - 2 * b) + b;
    return y;
  }
  else {
    return 2 * b;
  }
}
double line2(double x, double a, double b, double c) {
  if (4 * b != c) {
    double y = (x - c) * (b - abs(2 * b)-a) / (4 * b - c) + a;
    return y;
  }
  else {
    return 4 * b;
  }
}
double circle2(double x, double a, double b, double c) {
  double y = -sqrt(4 * pow(b, 2) - pow((x - 4 * b), 2)) + b;
  return y;
}
double line3(double x, double a, double b, double c) {
  if (c != 2 * b) {
    double y = (x - 6 * b) * (a - b) / (c - 2 * b) + b;
    return y;
  }
  else {
    return 6 * b;
  }
}
double line4(double x, double a, double b, double c) {
  if (4 * b != c) {
    double y = (x - c - 4 * b) * (b - abs(2 * b) - a) / (4 * b - c) + a;
    return y;
  }
  else {
    return 8 * b;
  }
}
