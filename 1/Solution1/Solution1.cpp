// 38*24
/*
������ ����� ��������
������: 1309
������: 1.1.1
���� ������: 21.09.2021
���� �����: 22.09.2021
*/
#include <iostream>
#include <iomanip>
#include <cstdio>


using namespace std;

int main()
{
  system("chcp 1251");
  cout << "�����: ������ ����� ��������\n������: 1309\n������: 1.1.1\n���� ������: 21.09.2021\n";
  cout << "���� �����:\n������������ �������: ����������� �������� ���������\n";
  cout << "5,0001 x^6 � 3,0001 x^4 � 9,0001 x^3\n";
  cout << "543,2 x^10 + 72,562 x^8 + 4365,32 x^7 + 1,2\n\n\n";

  cout << "������� � (� �������� ����������� ������� � ����� ������ ����������� �����): ";
  double x;
  cin >> x;
  cout << "������� 1\n\n";
  cout << "5,0001 x^6 � 3,0001 x^4 � 9,0001 x^3\n";
  double p = 5.0001 * x * x - 3.0001;
  cout << "p1 = " << setprecision(13) << p << endl;
  p = p * x - 9.0001;
  cout << "p2 = " << setprecision(14) << p << endl;
  p *= x * x * x;
  double v1 = p;
  cout << "answer1 = " << setprecision(15) << p << endl;
  cout << "\n543,2 x^10 + 72,562 x^8 + 4365,32 x^7 + 1,2\n";
  p = 543.2 * x * x + 72.562;
  cout << "p1 = " << setprecision(12) << p << endl;
  p = p * x + 4365.32;
  cout << "p2 = " << setprecision(10) << p << endl;
  p = p * x * x * x * x * x * x * x + 1.2;
  cout << "answer2 = " << setprecision(16) << p << endl;
  cout << "\nanswer1 * answer 2 = " << setprecision(30) << v1 * p;

  cout << "\n\n\n������� 2\n\n";
  v1 = ((5.0001 * x * x - 3.0001) * x - 9.0001) * x * x * x;
  cout << "5,0001 x^6 � 3,0001 x^4 � 9,0001 x^3 = " << setprecision(18) << v1 << endl;
  p = ((x * x * 543.2 + 72.562) * x + 4365.32) * x * x * x * x * x * x * x + 1.2;
  cout << "543,2 x^10 + 72,562 x^8 + 4365,32 x^7 + 1,2 = " << setprecision(22) << p << endl;
  cout << "ans1 * ans2 = " << setprecision(18) << v1 * p << endl;

  printf("\n\n������� 3\n\n������� � (� �������� ����������� ������� � ����� ������ ����������� �������) : ");
  scanf_s("%lf", &x);
  printf("\n5,0001 x^6 � 3,0001 x^4 � 9,0001 x^3   %f \n", x);
  p = 5.0001 * x * x - 3.0001;
  printf("p1 = %13.8lf\n", p);
  p = p * x - 9.0001;
  printf("p2 = %10.19lf\n", p);
  p *= x * x * x;
  printf("answer1 = %10.20lf\n", p);
  v1 = p;
  printf("\n543,2 x^10 + 72,562 x^8 + 4365,32 x^7 + 1,2\n");
  p = 543.2 * x * x + 72.562;
  printf("p1 = %18.8lf\n", p);
  p = p * x + 4365.32;
  printf("p2 = %20.5lf\n", p);
  p = p * x * x * x * x * x * x * x + 1.2;
  printf("answer2 = %13.4lf\n", p);
  printf("\nanswer1 * answer 2 = %10.10lf", v1 * p);
}
