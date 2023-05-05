#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "triangle.h"
using namespace std;
void dotouter(int,int,int,int,int,int);

int main()
{
	srand(time(0)); 
	int i, n, a, b, c;
	double rsum, isum, esum;
	rsum = 0;
	isum = 0;
	esum = 0;
	cout << "Введіть n(3 - 100): " << endl;
	cin >> n;
    a = n / 3;
    b = a;
    c = n - (a + b);
	TRtriangle rtriangle[a];
	TItriangle itriangle[b];
	TEtriangle etriangle[c];
	std::cout << "\n========================\n" << std::endl;
	cout << "Кількість прямокутних трикутників: " << a << "\nТочки трикутників:" << endl;
	for(i = 0; i < a; i++)
	{
		TRtriangle base = rtriangle[i];
		cout << i+1 << ")" << endl;
		dotouter(base.get_1axisX(),base.get_2axisX(),base.get_3axisX(),base.get_1axisY(),base.get_2axisY(),base.get_3axisY());
		rsum += base.square();
	}
	std::cout << "\n========================\n" << std::endl;
	cout << "Кількість рівнобедрених трикутників: " << b << "\nТочки трикутників:" << endl;
	for(i = 0; i < b; i++)
	{
		TItriangle base = itriangle[i];
		cout << a+i+1 << ")" << endl;
		dotouter(base.get_1axisX(),base.get_2axisX(),base.get_3axisX(),base.get_1axisY(),base.get_2axisY(),base.get_3axisY());
		isum += base.perimeter();
	}
	std::cout << "\n========================\n" << std::endl;
	cout << "Кількість рівносторонніх трикутників: " << c << "\nТочки трикутників:" << endl;
	for(i = 0; i < c; i++)
	{
		TEtriangle base = etriangle[i];
		cout << a+b+i+1 << ")" << endl;
		dotouter(base.get_1axisX(),base.get_2axisX(),base.get_3axisX(),base.get_1axisY(),base.get_2axisY(),base.get_3axisY());
		esum += base.square();
	}
	cout << "\nСума площ прямокутних трикутників: " << rsum << endl;
	cout << "\nСума площ рівносторонніх трикутників: " << esum << endl;
	cout << "\nСума периметрів рівнобедрених трикутників: " << isum << endl;
}

void dotouter(int x1, int x2, int x3, int y1, int y2, int y3)
{
	cout << "T1:" << x1 << " " << y1 << endl;
	cout << "T2:" << x2 << " " << y2 << endl;
	cout << "T3:" << x3 << " " << y3 << endl;
}