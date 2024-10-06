// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

double P0(const int K, const int N)
{
	double s = 0;
	for (int i = 1; i <= 15; i++)
		s *= (pow(sin(i),2) + pow(cos(1./i),2))/pow(i,2);
	return s;
}

double P1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2) * P1(K, N, i + 1);
}

double P2(const int K, const int N, const int i)
{
	if (i < K)
		return 0;
	else
		return (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2) * P2(K, N, i - 1);
}

double P3(const int K, const int N, const int i, double t)
{
	t = t * (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2);
	if (i >= N)
		return t;
	else
		return P3(K, N, i + 1, t);
}

double P4(const int K, const int N, const int i, double t)
{
	t = t * (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2);
	if (i <= K)
		return t;
	else
		return P4(K, N, i - 1, t);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(Спуск, спадає) P0 = " << P2(K, N, N) << endl;
	cout << "(Спуск, зростає) P1 = " << P1(K, N, K) << endl;
	cout << "(Підйом, спадає) P2 = " << P4(K, N, N, 0) << endl;
	cout << "(Підйом, зростає) P3 = " << P3(K, N, K, 0) << endl;
	cout << "(Ітераційний спосіб) P4 = " << P0(K, N) << endl;
	return 0;
}