#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int quickSort(int* E, int n);

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, sum = 0;
    cout << "Введите число товаров" << endl;
    cin >> n;
    int numberOfDiscountPositions = int(n / 2);
    int* A = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        *(A + i) =  1 + rand() % 60;
    }
    quickSort(A, n);
    int j = n - 1;
    if (n % 2 != 0)
    {
        j--;
    }
    for (int i = 0; i < numberOfDiscountPositions; i += 2)
    {
        swap(*(A + i), *(A + j));
        j -= 2;       
    }

    cout << "Порядок пробивания товаров: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(A + i) << " ";
    }
    for (int i = 0; i < n; i += 2)
    {
        sum += *(A + i);
    }
    cout << "\nМаскимальная сумма чека: " << sum << endl;
    delete[] A;
}