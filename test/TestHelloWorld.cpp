#include <gtest/gtest.h>

#include "HelloWorld.h"

TEST(TestHelloWorld, GetMessage)
{
    EXPECT_EQ("Hello, World!", HelloWorld::GetMessage());
}
