#include <gtest/gtest.h>

#include "LinkedList.h"

TEST(TestLinkedList, Empty)
{
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::invalid_argument);
}

// TODO Test IsEmpty returns false for at least one element (need Add functionality for that)
TEST(TestLinkedList, AddOneElement)
{
    LinkedList<int> list;
    list.Add(42);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(42, list.At(0));
}
