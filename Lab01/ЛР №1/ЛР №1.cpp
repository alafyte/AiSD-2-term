#include <iostream>
#include <ctime>

using namespace std; 

int fibNumber(unsigned int);

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите номер числа" << endl;
    unsigned int n;
    cin >> n;

    //Циклом
    unsigned int a = 0;
    unsigned int b = 1;

    double startTime1 = clock();
    for (int i = 0; i < n; i++)
    {
        a = a + b;
        b = a - b;
    }
    cout << n << "-ое число Фибоначчи равно: " << a << endl;
    double endTime1 = clock();
    double resultTime1 = (endTime1 - startTime1) / CLOCKS_PER_SEC;
    cout << "Время выполнения программы циклом: " << resultTime1 << " секунд(ы)" << endl;

    //Рекурсией
    double startTime2 = clock();
    cout << n << "-ое число Фибоначчи равно: " << fibNumber(n) << endl;
    double endTime2 = clock();
    double resultTime2 = (endTime2 - startTime2) / CLOCKS_PER_SEC;
    cout << "Время выполнения программы рекурсией: " << resultTime2 << " секунд(ы)" << endl;

    return 0;
}
