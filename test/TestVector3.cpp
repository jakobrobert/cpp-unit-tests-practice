#include <gtest/gtest.h>

#include "Vector3.h"

constexpr float FLOAT_TOLERANCE = 1e-6f;

void ExpectVector3Near(const Vector3& expected, const Vector3& actual, float tolerance)
{
    EXPECT_NEAR(expected.x, actual.x, tolerance);
    EXPECT_NEAR(expected.y, actual.y, tolerance);
    EXPECT_NEAR(expected.z, actual.z, tolerance);
}

TEST(TestVector3, DefaultConstructor)
{
    Vector3 v;
    EXPECT_EQ(0.f, v.x);
    EXPECT_EQ(0.f, v.y);
    EXPECT_EQ(0.f, v.z);
}

TEST(TestVector3, ParameterizedConstructor)
{
    Vector3 v(-1.0f, 1e6f, 1e-6f);
    // Note: Do not use ExpectVector3Near here. By using the constructor to create the expected vector, this would create a circular dependency and make the test meaningless.
    EXPECT_NEAR(-1.0f, v.x, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e6f, v.y, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e-6f, v.z, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorEqualityVectorsAreEqual)
{
    Vector3 v1(1.f, 2.f, 3.f);
    Vector3 v2(1.f, 2.f, 3.f);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 != v2);
}

TEST(TestVector3, OperatorEqualityVectorsAreNotEqual)
{
    Vector3 v1(1.f, 2.f, 3.f);
    Vector3 v2(1.f, 2.f, 4.f);
    EXPECT_FALSE(v1 == v2);
    EXPECT_TRUE(v1 != v2);
}

TEST(TestVector3, OperatorPlusEquals)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);
    Vector3 v2(4.4f, 5.5f, 6.6f);

    v1 += v2;

    Vector3 expected(5.5f, 7.7f, 9.9f);
    ExpectVector3Near(expected, v1, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorPlus)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);
    Vector3 v2(4.4f, 5.5f, 6.6f);

    Vector3 actual = v1 + v2;

    Vector3 expected(5.5f, 7.7f, 9.9f);
    ExpectVector3Near(expected, actual, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorMinusEquals)
{
    Vector3 v1(5.5f, 7.7f, 9.9f);
    Vector3 v2(4.4f, 5.5f, 6.6f);

    v1 -= v2;

    Vector3 expected(1.1f, 2.2f, 3.3f);
    ExpectVector3Near(expected, v1, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorMinus)
{
    Vector3 v1(5.5f, 7.7f, 9.9f);
    Vector3 v2(4.4f, 5.5f, 6.6f);

    Vector3 actual = v1 - v2;

    Vector3 expected(1.1f, 2.2f, 3.3f);
    ExpectVector3Near(expected, actual, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorMultiplyEquals)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);

    v1 *= 42.42f;
    
    Vector3 expected(46.662f, 93.324f, 139.986f);
    ExpectVector3Near(expected, v1, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorMultiply)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);

    Vector3 actual = v1 * 42.42f;
    
    Vector3 expected(46.662f, 93.324f, 139.986f);
    ExpectVector3Near(expected, actual, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorDivideEquals)
{
    Vector3 v1(46.662f, 93.324f, 139.986f);

    v1 /= 42.42f;

    Vector3 expected(1.1f, 2.2f, 3.3f);
    ExpectVector3Near(expected, v1, FLOAT_TOLERANCE);
}

TEST(TestVector3, OperatorDivide)
{
    Vector3 v1(46.662f, 93.324f, 139.986f);

    Vector3 actual = v1 / 42.42f;
    
    Vector3 expected(1.1f, 2.2f, 3.3f);
    ExpectVector3Near(expected, actual, FLOAT_TOLERANCE);
}

TEST(TestVector3, DotProduct)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);
    Vector3 v2(4.4f, 5.5f, 6.6f);
    EXPECT_NEAR(38.72f, v1.DotProduct(v2), FLOAT_TOLERANCE);
}

TEST(TestVector3, CrossProduct)
{
    Vector3 v1(1.1f, 2.2f, 3.3f);
    Vector3 v2(4.4f, 5.5f, 6.6f);

    Vector3 actual = v1.CrossProduct(v2);

    Vector3 expected(-3.63f, 7.26f, -3.63f);
    ExpectVector3Near(expected, actual, FLOAT_TOLERANCE);
}
