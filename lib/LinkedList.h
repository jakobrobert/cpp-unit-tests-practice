#pragma once

template <typename T>
class LinkedList
{
public:
    void Add(T value) { }

    bool IsEmpty() const { return true; }
    size_t Size() const { return 0; }
    T At(size_t index) const { return T(); }
};
