#include <iostream>

int arrayCopy(int *A, int *other, int n)
{
	for (int i = 0; i < n; i++)
		*(other + i) = *(A + i);
	return *other;
}