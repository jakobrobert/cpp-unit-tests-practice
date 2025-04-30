#include <gtest/gtest.h>
#include <memory>

#include "LinkedListSimple.h"
#include "LinkedListWithSentinelNode.h"

enum class ListType
{
    Simple,
    WithSentinelNode
};

template <typename T>
std::unique_ptr<List<T>> CreateList(ListType type)
{
    switch (type)
    {
        case ListType::Simple:
            return std::make_unique<LinkedListSimple<T>>();
        case ListType::WithSentinelNode:
            return std::make_unique<LinkedListWithSentinelNode<T>>();
        default:
            throw std::invalid_argument("Invalid ListType");
    }
}

class TestListParameterized : public ::testing::TestWithParam<ListType> {};

// TODO Refactor: Make tests parameterized to instantiate both list impls for each test, reduce duplication.
// -> First, only for test "Empty", merge both into one parameterized test.
// -> Then for all other tests, expect all to fail because not implemented yet
TEST_P(TestListParameterized, Empty)
{
    const ListType listType = GetParam();
    std::unique_ptr<List<int>> list = CreateList<int>(listType);
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

INSTANTIATE_TEST_SUITE_P(
    ListImplementations,
    TestListParameterized,
    ::testing::Values(ListType::Simple, ListType::WithSentinelNode)
);
