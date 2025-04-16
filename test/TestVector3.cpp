#include <gtest/gtest.h>

#include "Vector3.h"

constexpr float FLOAT_TOLERANCE = 1e-6f;

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

    EXPECT_NEAR(5.5f, v1.x, FLOAT_TOLERANCE);
    EXPECT_NEAR(7.7f, v1.y, FLOAT_TOLERANCE);
    EXPECT_NEAR(9.9f, v1.z, FLOAT_TOLERANCE);
}
