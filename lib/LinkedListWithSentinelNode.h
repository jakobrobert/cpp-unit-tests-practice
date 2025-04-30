#pragma once

#include "List.h"

#include <stdexcept>

template <typename T>
class LinkedListWithSentinelNode : public List<T>
{
public:
    ~LinkedListWithSentinelNode() override
    {
        Clear();
    }

    void Add(const T& value) override
    {

    }

    void RemoveFirst() override
    {

    }

    void Clear() override
    {

    }

    bool IsEmpty() const override
    {
        return true;
    }

    size_t Size() const override
    {
        return 0; 
    }

    const T& At(size_t index) const override
    {
        throw std::out_of_range("list is empty");
    }
};
