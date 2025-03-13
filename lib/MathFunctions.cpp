#include "MathFunctions.h"

#include <stdexcept>

int MathFunctions::Factorial(int n)
{
    if (n < 0)
        throw std::invalid_argument("Factorial is not defined for negative numbers");

    if (n < 2)
        return 1;

    return n * Factorial(n - 1);
}
