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
    double sum = 0.0;

    for (double number : numbers)
        sum += number;

    return sum;
}

double MathFunctions::Average(const std::vector<double>& numbers)
{
    if (numbers.empty())
        throw std::invalid_argument("Average is not defined for empty input");

    return Sum(numbers) / numbers.size();
}
