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
