#include <iostream>
using namespace std;

void showArray(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(A + i) << "\t";

	cout << endl << endl;
}