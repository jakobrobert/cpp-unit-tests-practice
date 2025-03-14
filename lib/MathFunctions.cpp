#include "MathFunctions.h"

#include <stdexcept>

int MathFunctions::Factorial(int n)
{
    if (n < 0)
        throw std::invalid_argument("Factorial is not defined for negative numbers");

    if (n < 2)
        return 1;

    if (n > 12)
        throw std::overflow_error("Factorial leads to overflow for n > 12");

    return n * Factorial(n - 1);
}
