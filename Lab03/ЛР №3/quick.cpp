#include <iostream>
using namespace std;

int quickSort(int* E, int n)
{
    int i = 0;
    int j = n - 1;
    int mid = *(E + n / 2);


    do {

        while (*(E + i) < mid)
            i++;

        while (*(E + j) > mid)
            j--;

        if (i <= j) {
            swap(*(E + i), *(E + j));
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0)
        quickSort(E, j + 1);

    if (i < n)
        quickSort((E + i), n - i);

    return *E;
};
