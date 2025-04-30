#include <gtest/gtest.h>

#include "LinkedListSimple.h"

TEST(TestLinkedList, Empty)
{
    LinkedListSimple<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::out_of_range);
}

TEST(TestLinkedList, AddOneElement)
{
    LinkedListSimple<int> list;
    list.Add(42);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(42, list.At(0));
    EXPECT_THROW(list.At(1), std::out_of_range);
}

TEST(TestLinkedList, RemoveOneElement)
{
    LinkedListSimple<int> list;

    list.Add(42);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(42, list.At(0));
    EXPECT_THROW(list.At(1), std::out_of_range);

    list.RemoveFirst();
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::out_of_range);
}

TEST(TestLinkedList, AddMultipleElements)
{
    LinkedListSimple<int> list;
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

TEST(TestLinkedList, RemoveMultipleElements)
{
    LinkedListSimple<int> list;

    list.Add(3);
    list.Add(1);
    list.Add(2);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(3, list.At(0));
    EXPECT_EQ(1, list.At(1));
    EXPECT_EQ(2, list.At(2));
    EXPECT_THROW(list.At(3), std::out_of_range);

    list.RemoveFirst();
    list.RemoveFirst();
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(1, list.Size());
    EXPECT_EQ(2, list.At(0));
    EXPECT_THROW(list.At(1), std::out_of_range);
}

TEST(TestLinkedList, TryToRemoveFromEmptyList)
{
    LinkedListSimple<int> list;
    EXPECT_THROW(list.RemoveFirst(), std::out_of_range);
}

TEST(TestLinkedList, Clear)
{
    LinkedListSimple<int> list;

    list.Add(3);
    list.Add(1);
    list.Add(2);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(3, list.Size());
    EXPECT_EQ(3, list.At(0));
    EXPECT_EQ(1, list.At(1));
    EXPECT_EQ(2, list.At(2));
    EXPECT_THROW(list.At(3), std::out_of_range);

    list.Clear();
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(0, list.Size());
    EXPECT_THROW(list.At(0), std::out_of_range);
}
