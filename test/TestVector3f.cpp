#include <gtest/gtest.h>

#include "Vector3f.h"

constexpr float FLOAT_TOLERANCE = 1e-6f;

TEST(TestVector3f, DefaultConstructor)
{
    Vector3f v;
    EXPECT_EQ(0.f, v.x);
    EXPECT_EQ(0.f, v.y);
    EXPECT_EQ(0.f, v.z);
}

TEST(TestVector3f, ParameterizedConstructor)
{
    Vector3f v(-1.0f, 1e6f, 1e-6f);
    EXPECT_NEAR(-1.0f, v.x, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e6f, v.y, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e-6f, v.z, FLOAT_TOLERANCE);
}

TEST(TestVector3f, OperatorEqualityVectorsAreEqual)
{
    Vector3f v1(1.f, 2.f, 3.f);
    Vector3f v2(1.f, 2.f, 3.f);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 != v2);
}

TEST(TestVector3f, OperatorEqualityVectorsAreNotEqual)
{
    Vector3f v1(1.f, 2.f, 3.f);
    Vector3f v2(1.f, 2.f, 4.f);
    EXPECT_FALSE(v1 == v2);
    EXPECT_TRUE(v1 != v2);
}
