#include <gtest/gtest.h>

#include "LinkedList.h"

TEST(TestLinkedList, Empty)
{
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::out_of_range);
}

TEST(TestLinkedList, AddOneElement)
{
    LinkedList<int> list;
    list.Add(42);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(42, list.At(0));
    EXPECT_THROW(list.At(1), std::out_of_range);
}

TEST(TestLinkedList, RemoveOneElement)
{
    LinkedList<int> list;

    list.Add(42);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(42, list.At(0));
    EXPECT_THROW(list.At(1), std::out_of_range);

    list.RemoveLast();
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::out_of_range);
}

TEST(TestLinkedList, AddMultipleElements)
{
    LinkedList<int> list;
    list.Add(3);
    list.Add(1);
    list.Add(2);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(3, list.At(0));
    EXPECT_EQ(1, list.At(1));
    EXPECT_EQ(2, list.At(2));
    EXPECT_THROW(list.At(3), std::out_of_range);
}

// TODO Test RemoveMultipleElements

