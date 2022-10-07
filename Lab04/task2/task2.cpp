#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, first_place = 0, second_place = 0, third_place = 0, result = 0;
    cout << "Введите число участников: " << endl;
    cin >> n;
    int* A = new int[n];

    srand(time(NULL));

    cout << "Результаты участников: " << endl;
    for (int i = 0; i < n; i++)
    {
        *(A + i) = 1 + rand() % 100;
        cout << *(A + i) << " ";
    }

    for (int i = 0; i < n ; i ++)
    {
        first_place = max(*(A + i), first_place);
    }
    for (int i = 0; i < n; i++)
    {
        if (*(A + i) > second_place && *(A + i) != first_place)
            second_place = *(A + i);
    }

    for (int i = 0; i < n; i++)
    {
        if (*(A + i) > third_place && *(A + i) != first_place && *(A + i) != second_place)
            third_place = *(A + i);
    }


    for (int i = 0; i < n; i++)
        if (*(A + i) == first_place || *(A + i) == second_place || *(A + i) == third_place)
            result++;
    cout << "\n\nПервое место: " << first_place << " баллов" << endl;
    cout << "Второе место: " << second_place << " баллов" << endl;
    cout << "Третье место: " << third_place <<  " баллов" << endl;
    cout << "\nКоличество призеров: " << result << endl;
    delete[] A;
}