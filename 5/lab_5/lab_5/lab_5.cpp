#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  fstream f_in("../input.txt");
  int N, M, K;
  f_in >> N >> M >> K;


  double **Arr = new double*[N];
  for (int i = 0; i < N; i++)
  {
    Arr[i] = new double[N];
    for (int j = 0; j < N; j++)
    {
      f_in >> Arr[i][j];
    }
  }

  //get x
  int x_count = 0;
  int x_num = 2 * N + (N - K - 1);
  double* X = new double[x_num];
  for (int i = 0; i < N; i++)
  {
    X[x_count] = Arr[K-1][i];
    x_count++;
  }
  for (int i = 0; i < N ; i++)
  {
    X[x_count] = Arr[N - 1][i];
    x_count++;
  }
  for (int i = K; i < N-1; i++)
  {
    X[x_count] = Arr[i][M-1];
    x_count++;
  }

  // print X
  for (int i = 0; i <= (2 * N + (N - K - 2)); i++) {
    cout << X[i] << " ";
  }
  cout << endl << endl;


  // print arr
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << Arr[i][j] << " ";
    }
    cout << endl;
  }

  //find max
  double mx = -9999999999999999;
  for (int i = 0; i < x_num; i++)
  {
    if (X[i] > mx)
      mx = X[i];
  }
  cout <<"max item = "<< mx;
}
