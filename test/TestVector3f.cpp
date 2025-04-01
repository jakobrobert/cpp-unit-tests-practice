#include <gtest/gtest.h>

#include "Vector3f.h"

constexpr float FLOAT_TOLERANCE = 1e-6f;

TEST(TestVector3f, DefaultConstructor)
{
    Vector3f vector;
    EXPECT_EQ(0.f, vector.x);
    EXPECT_EQ(0.f, vector.y);
    EXPECT_EQ(0.f, vector.z);
}

TEST(TestVector3f, ParameterizedConstructor)
{
    Vector3f vector(-1.0f, 1e6f, 1e-6f);
    EXPECT_NEAR(-1.0f, vector.x, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e6f, vector.y, FLOAT_TOLERANCE);
    EXPECT_NEAR(1e-6f, vector.z, FLOAT_TOLERANCE);
}

TEST(TestVector3f, OperatorEqualsReturnsTrue)
{
    Vector3f vec1(1.f, 2.f, 3.f);
    Vector3f vec2(1.f, 2.f, 3.f);
    EXPECT_TRUE(vec1 == vec2);
    // TODO test != as well
}

TEST(TestVector3f, OperatorEqualsReturnsFalse)
{
    Vector3f vec1(1.f, 2.f, 3.f);
    Vector3f vec2(1.f, 2.f, 4.f);
    EXPECT_FALSE(vec1 == vec2);
    // TODO test != as well
}
