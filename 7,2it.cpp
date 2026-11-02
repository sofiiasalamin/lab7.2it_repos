// Lab_7_2_1.cpp
// Варіант 26
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int m, const int Low, const int High);
void Print(int** a, const int n, const int m);
int SumAntiDiagonal(int** a, const int n, const int m);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -7;
    int High = 65;

    int n, m;                        // n – кількість рядків, m – кількість стовпців
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    int** a = new int* [n];          // a – масив вказівників на рядки матриці
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    Create(a, n, m, Low, High);
    Print(a, n, m);

    cout << "sum of anti-diagonal = " << SumAntiDiagonal(a, n, m) << endl;

    for (int i = 0; i < n; i++)       // i – номер рядка, j – номер стовпчика
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int m, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int m)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}


// s – сума; i – номер рядка; j – номер стовпця побічної діагоналі;
// k – кількість елементів побічної діагоналі.
int SumAntiDiagonal(int** a, const int n, const int m)
{
    int s = 0;
    int k = (n < m) ? n : m;
    for (int i = 0; i < k; i++)
    {
        int j = m - 1 - i;            // стовпчик побічної діагоналі в рядку i
        s += a[i][j];
    }
    return s;
}