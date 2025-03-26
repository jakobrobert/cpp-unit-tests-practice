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

double MathFunctions::Min(const std::vector<double>& numbers)
{
    double min = std::numeric_limits<double>::max();

    for (double number : numbers)
    {
        if (number < min)
            min = number;
    }

    return min;
}

double MathFunctions::Sum(const std::vector<double>& numbers)
{
    if (numbers.empty())
        return 0.0;

    return numbers.front();
}
