#include <gtest/gtest.h>

#include "MathFunctions.h"

TEST(TestMathFunctions, FactorialOfNegativeNumber)
{
    EXPECT_THROW(MathFunctions::Factorial(-1), std::invalid_argument);
}

TEST(TestMathFunctions, FactorialOfZero)
{
    EXPECT_EQ(1, MathFunctions::Factorial(0));
}

TEST(TestMathFunctions, FactorialOfOne)
{
    EXPECT_EQ(1, MathFunctions::Factorial(1));
}

TEST(TestMathFunctions, FactorialOfTwo)
{
    EXPECT_EQ(2, MathFunctions::Factorial(2));
}

TEST(TestMathFunctions, FactorialOfThree)
{
    EXPECT_EQ(6, MathFunctions::Factorial(3));
}

TEST(TestMathFunctions, FactorialOfFour)
{
    EXPECT_EQ(24, MathFunctions::Factorial(4));
}

TEST(TestMathFunctions, FactorialOfTwelve)
{
    EXPECT_EQ(479001600, MathFunctions::Factorial(12));
}

TEST(TestMathFunctions, FactorialOfThirteen)
{
    EXPECT_THROW(MathFunctions::Factorial(13), std::overflow_error);
}

TEST(TestMathFunctions, MinOfEmptyInput)
{
    std::vector<double> numbers;
    EXPECT_EQ(std::numeric_limits<double>::max(), MathFunctions::Min(numbers));
}

TEST(TestMathFunctions, MinOfOneNumber)
{
    std::vector<double> numbers{42.0};
    EXPECT_EQ(42.0, MathFunctions::Min(numbers));
}

TEST(TestMathFunctions, MinOfMultipleNumbers)
{
    std::vector<double> numbers{42.0, 16.9, 67.6};
    EXPECT_EQ(16.9, MathFunctions::Min(numbers));
}
