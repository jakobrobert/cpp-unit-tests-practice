#include <gtest/gtest.h>

#include "MathFunctions.h"

// TODO Test exception for negative input

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