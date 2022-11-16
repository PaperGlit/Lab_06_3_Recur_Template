#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

template <typename T>
void Create(T* a, const int size, T Low, T High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

template <typename P>
void Print(P* a, const int size, int i)
{
	if (i < 1)
		cout << "Значення масиву : ";
	if (i < size)
	{
		cout << a[i] << " ";
		Print(a, size, i + 1);
	}
	else
		cout << endl;
}

template <typename D>
D Min(D* a, const int size, D min, int j)
{
	if (j < size)
	{
		if (min > a[j])
			min = a[j];
		Min(a, size, min, j + 1);
	}
	else
		return min;
}

template <typename R>
int iMin(R* a, const int size, R min, int imin, int j)
{
	if (j < size)
	{
		if (min > a[j])
		{
			min = a[j];
			imin = j;
		}
		iMin(a, size, min, imin, j + 1);
	}
	else
		return imin;
}

template <typename Q>
Q* Sort(Q* a, const int size, int i, Q min, int imin)
{
	if (i < size - 1)
	{
		min = Min(a, size, a[i], i + 1);
		imin = iMin(a, size, a[i], i, i + 1);
		a[imin] = a[i];
		a[i] = min;
		Sort(a, size, i + 1, min, imin);
	}
	else
		return a;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n, Low, High;

	cout << "n = "; cin >> n;
	cout << "min = "; cin >> Low;
	cout << "max = "; cin >> High;

	int* c = new int[n];

	Create(c, n, Low, High, 0);
	Print(c, n, 0);
	Print(Sort(c, n, 0, 0, 0), n, 0);

	return 0;
}