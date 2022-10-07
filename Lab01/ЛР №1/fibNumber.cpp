#include <iostream>

int fibNumber(unsigned int number)
{

    if (number == 0)
        return 0;

    if (number == 1)
        return 1;

    return fibNumber(number - 1) + fibNumber(number - 2);

}
