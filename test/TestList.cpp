#include <gtest/gtest.h>
#include <memory>

#include "LinkedListSimple.h"

TEST(TestList, Empty)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();
    EXPECT_TRUE(list->IsEmpty());
    EXPECT_EQ(0, list->Size());
    EXPECT_THROW(list->At(0), std::out_of_range);
}

TEST(TestList, AddOneElement)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();
    list->Add(42);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(1, list->Size());
    EXPECT_EQ(42, list->At(0));
    EXPECT_THROW(list->At(1), std::out_of_range);
}

TEST(TestList, RemoveOneElement)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();

    list->Add(42);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(1, list->Size());
    EXPECT_EQ(42, list->At(0));
    EXPECT_THROW(list->At(1), std::out_of_range);

    list->RemoveFirst();
    EXPECT_TRUE(list->IsEmpty());
    EXPECT_EQ(0, list->Size());
    EXPECT_THROW(list->At(0), std::out_of_range);
}

TEST(TestList, AddMultipleElements)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();
    list->Add(3);
    list->Add(1);
    list->Add(2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);
}

TEST(TestList, RemoveMultipleElements)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();

    list->Add(3);
    list->Add(1);
    list->Add(2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);

    list->RemoveFirst();
    list->RemoveFirst();
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(1, list->Size());
    EXPECT_EQ(2, list->At(0));
    EXPECT_THROW(list->At(1), std::out_of_range);
}

TEST(TestList, TryToRemoveFromEmptyList)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();
    EXPECT_THROW(list->RemoveFirst(), std::out_of_range);
}

TEST(TestList, Clear)
{
    std::unique_ptr<List<int>> list = std::make_unique<LinkedListSimple<int>>();

    list->Add(3);
    list->Add(1);
    list->Add(2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);

    list->Clear();
    EXPECT_TRUE(list->IsEmpty());
    EXPECT_EQ(0, list->Size());
    EXPECT_THROW(list->At(0), std::out_of_range);
}
