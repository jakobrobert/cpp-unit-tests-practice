#include <gtest/gtest.h>

#include "LinkedList.h"

TEST(TestLinkedList, IsEmptyReturnsTrueForEmptyList)
{
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
}

// TODO Test IsEmpty returns false for at least one element (need Add functionality for that)