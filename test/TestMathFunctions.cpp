#include <gtest/gtest.h>

#include "MathFunctions.h"

TEST(TestMathFunctions, FactorialOfZero)
{
    EXPECT_EQ(1, MathFunctions::Factorial(0));
}
