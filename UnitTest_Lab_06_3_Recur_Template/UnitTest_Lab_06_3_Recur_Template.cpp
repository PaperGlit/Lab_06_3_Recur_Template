#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3_Recur_Template/Lab_06_3_Recur_Template.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template <typename V>
void Loop(V* a, V* c, const int size, int i)
{
	if (i < size)
	{
		Assert::AreEqual(c[i], a[i]);
		Loop(a, c, size, i + 1);
	}
}

template <typename H>
H TestMin(H* a, const int size, H min, int j)
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

template <typename X>
int TestiMin(X* a, const int size, X min, int imin, int j)
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

template <typename S>
void Test(S* a, S* c, const int size, int i, S min, int imin)
{
	if (i < size - 1)
	{
		min = TestMin(c, size, c[i], i + 1);
		imin = TestiMin(c, size, c[i], i, i + 1);
		c[imin] = c[i];
		c[i] = min;
		Loop(a, c, size, 0);
		Test(a, c, size, i + 1, min, imin);
	}
}

namespace UnitTestLab063Recur
{
	TEST_CLASS(UnitTestLab063Recur)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n];
			int Low = -10, High = 10;
			Create(c, n, Low, High, 0);
			int* a = Sort(c, n, 0, 0, 0);
			Test(a, c, n, 0, 0, 0);
		}
	};
}