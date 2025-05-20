#include <gtest/gtest.h>
#include <memory>

#include "LinkedListSimple.h"
#include "LinkedListSentinel.h"

enum class ListType
{
    Simple,
    Sentinel
};

template <typename T>
std::unique_ptr<List<T>> CreateList(ListType type)
{
    switch (type)
    {
        case ListType::Simple:
            return std::make_unique<LinkedListSimple<T>>();
        case ListType::Sentinel:
            return std::make_unique<LinkedListSentinel<T>>();
        default:
            throw std::invalid_argument("Invalid ListType");
    }
}

class TestList : public ::testing::TestWithParam<ListType> {};

TEST_P(TestList, Empty)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    EXPECT_TRUE(list->IsEmpty());
    EXPECT_EQ(0, list->Size());
    EXPECT_THROW(list->At(0), std::out_of_range);
}

TEST_P(TestList, AddMultipleElements)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
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

TEST_P(TestList, InsertMultipleElementsAtBeginning)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    list->InsertAt(0, 3);
    list->InsertAt(0, 1);
    list->InsertAt(0, 2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(2, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(3, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);
}

TEST_P(TestList, InsertMultipleElementsAtEnd)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    list->InsertAt(list->Size(), 3);
    list->InsertAt(list->Size(), 1);
    list->InsertAt(list->Size(), 2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);
}

TEST_P(TestList, InsertMultipleElementsInMiddle)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    list->InsertAt(0, 1);
    std::cout << list->At(0) << std::endl;
    list->InsertAt(1, 2);
    std::cout << list->At(0) << ", " << list->At(1) << std::endl;
    list->InsertAt(1, 3);
    std::cout << list->At(0) << ", " << list->At(1) << ", " << list->At(2) << std::endl;
    list->InsertAt(2, 4);
    std::cout << list->At(0) << ", " << list->At(1) << ", " << list->At(2) << ", " << list->At(3) << std::endl;
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(4, list->Size());
    EXPECT_EQ(1, list->At(0));
    EXPECT_EQ(3, list->At(1));
    EXPECT_EQ(4, list->At(2));
    EXPECT_EQ(2, list->At(3));
    EXPECT_THROW(list->At(4), std::out_of_range);
}

// TODO Test: Insert with index out of range, e.g. empty list, try insert at 1

// TODO Later: Remove this test, remove method RemoveFirst
TEST_P(TestList, RemoveMultipleElements)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());

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

TEST_P(TestList, RemoveMultipleElementsAtBeginning)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());

    list->Add(3);
    list->Add(1);
    list->Add(2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);

    list->RemoveAt(0);
    list->RemoveAt(0);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(1, list->Size());
    EXPECT_EQ(2, list->At(0));
    EXPECT_THROW(list->At(1), std::out_of_range);
}

TEST_P(TestList, RemoveMultipleElementsAtEnd)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());

    list->Add(3);
    list->Add(1);
    list->Add(2);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(3, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_EQ(1, list->At(1));
    EXPECT_EQ(2, list->At(2));
    EXPECT_THROW(list->At(3), std::out_of_range);

    list->RemoveAt(list->Size() - 1);
    list->RemoveAt(list->Size() - 1);
    EXPECT_FALSE(list->IsEmpty());
    EXPECT_EQ(1, list->Size());
    EXPECT_EQ(3, list->At(0));
    EXPECT_THROW(list->At(1), std::out_of_range);
}

// TODO Test: Remove multiple in middle

TEST_P(TestList, TryToRemoveFromEmptyList)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    EXPECT_THROW(list->RemoveFirst(), std::out_of_range);
}

TEST_P(TestList, TryToRemoveFromEmptyListNew) // TODO Rename & remove old test using RemoveFirst
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());
    EXPECT_THROW(list->RemoveAt(0), std::out_of_range);
}

// TODO Test: Remove from invalid index -> list has 3 elements, remove at index 3

TEST_P(TestList, Clear)
{
    std::unique_ptr<List<int>> list = CreateList<int>(GetParam());

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
    TestList,
    ::testing::Values(ListType::Simple, ListType::Sentinel),
    [](const testing::TestParamInfo<ListType>& info) {
        switch (info.param)
        {
            case ListType::Simple: return "Simple";
            case ListType::Sentinel: return "Sentinel";
            default: return "Unknown";
        }
    }
);
