#include <iostream>

#include "MathFunctions.h"

long long power( long long x, long long y )
{
    int base = x, exp = y, i, result = 1;

    for( long long i = 0; i < exp; i++ )
    {
        result = result * base;
    }
    return result;
}
