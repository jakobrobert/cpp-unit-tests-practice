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
    if (numbers.empty())
        return std::numeric_limits<double>::max();

    double min = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }

    return min;
}
