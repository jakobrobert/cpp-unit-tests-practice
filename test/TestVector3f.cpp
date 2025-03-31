#include <gtest/gtest.h>

#include "Vector3f.h"

TEST(TestVector3f, DefaultConstructor)
{
    Vector3f vector;
    EXPECT_EQ(0.f, vector.x);
    EXPECT_EQ(0.f, vector.y);
    EXPECT_EQ(0.f, vector.z);
}
