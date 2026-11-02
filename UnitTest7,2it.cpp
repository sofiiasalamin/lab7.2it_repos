#include "pch.h"
#include "CppUnitTest.h"
#include "../7,2it/7,2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIter
{
	TEST_CLASS(UnitTestIter)
	{
	public:

		
		static int** MakeMatrix(const int n, const int m, const int* v)
		{
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
				for (int j = 0; j < m; j++)
					a[i][j] = v[i * m + j];
			}
			return a;
		}
			
		

		TEST_METHOD(SumAntiDiagonal_OneElement_ReturnsElement)
		{
			int v[1] = { 7 };
			int** a = MakeMatrix(1, 1, v);
			Assert::AreEqual(7, SumAntiDiagonal(a, 1, 1));
			
		}

		TEST_METHOD(SumAntiDiagonal_Square3x3_Returns15)
		{
			int v[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };   // 3 + 5 + 7
			int** a = MakeMatrix(3, 3, v);
			Assert::AreEqual(15, SumAntiDiagonal(a, 3, 3));
			
		}
				
		TEST_METHOD(Create_ValuesInRange)
		{
			const int n = 5, m = 6, Low = -7, High = 65;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
				for (int j = 0; j < m; j++)
					a[i][j] = 1000;                      
			}
			Create(a, n, m, Low, High);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					Assert::IsTrue(a[i][j] >= Low);
					Assert::IsTrue(a[i][j] <= High);
				}
			
		}
	};
}