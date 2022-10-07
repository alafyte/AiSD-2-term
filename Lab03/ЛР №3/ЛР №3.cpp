#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;
int arrayCopy(int*, int*, int);
void showArray(int*, int);
int quickSort(int*, int);

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];
    int* C = new int[n];
    int* D = new int[n];
    int* E = new int[n];

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 1000;
    }
    cout << "Элементы массива A:" << endl;
    showArray(A, n);
    

    //Пузырьковая сортировка
    arrayCopy(A, B, n);
    double start_time1 = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (*(B + j) > *(B + j + 1)) {
                swap(*(B + j), *(B + j + 1));
            }
        }
    }
    double end_time1 = clock();
    double result_time1 = end_time1 - start_time1;
    cout << "Элементы массива B:" << endl;
    showArray(B, n); 
    



    //Сортировка методом Шелла
    arrayCopy(A, C, n);
    double start_time2 = clock();
    int d, j;
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && *(C + j) > *(C + j + d))
            {
                swap(*(C + j), *(C + j + d));
                j--;
            }
        }
        d = d / 2;
    }
    double end_time2 = clock();
    double result_time2 = end_time2 - start_time2;
    cout << "Элементы массива С:" << endl;
    showArray(C, n);
    


    //Сортировка выбора
    arrayCopy(A, D, n);
    double start_time3 = clock();
    int count, key;
    for (int i = 0; i < n - 1; i++)
    {
        count = *(D + i); 
        key = i;
        for (j = i + 1; j < n; j++)
            if (*(D + j) < *(D + key)) 
                key = j;

        if (key != i)
        {
            *(D + i) = *(D + key);
            *(D + key) = count;
        }
    }
    double end_time3 = clock();
    double result_time3 = end_time3 - start_time3;
    cout << "Элементы массива D:" << endl;
    showArray(D, n);
    


    //Быстрая сортировка
    arrayCopy(A, E, n);
    double start_time4 = clock();
    quickSort(E, n);
    double end_time4 = clock();
    double result_time4 = end_time4 - start_time4;
    cout << "Элементы массива E:" << endl;
    showArray(E, n);
    
    //Вывод времени выполнения
    printf("Время выполнения пузырьковой сортировкой: %.2lf милисекунд(ы)\n\n\n", result_time1);
    printf("Время выполнения сортировкой методом Шелла: %.2lf милисекунд(ы)\n\n\n", result_time2);
    printf("Время выполнения сортировкой выбора: %lf милисекунд(ы)\n\n\n", result_time3);
    printf("Время выполнения быстрой сортировкой: %lf милисекунд(ы)\n\n\n", result_time4);

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;
}


