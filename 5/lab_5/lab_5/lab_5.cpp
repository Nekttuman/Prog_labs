#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

int check_N(fstream& f_in, int prev_n);
void read_a(double** Arr, fstream& f_in, int N);
void print_arr(double** Arr, int N, fstream& f_out);
double find_max(double** Arr, int N, int col, int row);


int main()
{
  fstream f_in("../input.txt");
  if (!f_in.is_open())
  {
    cout << "input file open error.";
    return -1;
  }
  fstream f_out("../output.txt", fstream::trunc | fstream::out);
  if (!f_out.is_open()) {
    cout << "output file open error.";
    return -1;
  }
  int N, col, row;
  f_in >> N >> col >> row;
  col -= 1; row -= 1;
  f_in.seekg(2, ios::cur);

  N = check_N(f_in, N);
  if (N == 0) {
    cout << "N is null";
    f_out << "N is null";
    return 0;
  }

  //init arr
  double **Arr = new double*[N];
  for (int i = 0; i < N; i++)
  {
    Arr[i] = new double[N];
  }

  read_a(Arr, f_in, N);

  f_out << "m = " << col + 1 << "\nk = " << row+1 << endl;
  print_arr(Arr, N, f_out);

  double mx = find_max(Arr, N, col, row);
  cout << mx;
  f_out << "max item = " << mx;
}

double find_max(double** Arr, int N, int col, int row) {
  double max = -INFINITY;
  for (int i = 0; i < N; i++) {
    if (Arr[row][i] > max)
      max = Arr[row][i];
    if (Arr[N - 1][i] > max)
      max = Arr[N - 1][i];
  }
  for (int i = row + 1; i < N; i++) {
    if (Arr[i][col] >= max)
      max = Arr[i][col];
  }
  return max;
}

int check_N(fstream& f_in, int prev_n) {
  //  курсор в файле должн находится непосредственно в начале первой строки таблицы
  if (prev_n < 0)
    return 0;
  int len = 1;
  int min_len = 30000;
  int strings_count = 0;
  string l;
  while (getline(f_in, l)) {
    strings_count++;
    //   cout << l<<endl;
    for (int i = 0; i < l.size(); i++) {
      if (l[i] == ' ')
        len++;
    }
    if (len < min_len)
      min_len = len;
  }

  return min(min(min_len, strings_count), prev_n);
}

void read_a(double** Arr, fstream& f_in, int N) {
  string tmp;
  f_in.clear();
  f_in.seekg(ios::beg);
  for (int i = 0; i < 3; i++)
    getline(f_in, tmp);

  string line;
  int a = 0;
  char ch_tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      f_in >> setiosflags(ios::skipws) >> Arr[i][j];
    }
    f_in >> resetiosflags(ios::skipws) >> ch_tmp;
    while (ch_tmp != '\n')
      f_in >> ch_tmp;
  }
}

void print_arr(double** Arr, int N, fstream& f_out) {
  f_out << "N = " << N << endl;
  f_out << "table = \n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      f_out << Arr[i][j] << " ";
      cout << Arr[i][j] << " ";
    }
    f_out << endl;
    cout << endl;
  }
}