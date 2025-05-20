#pragma once

template <typename T>
class List
{
public:
    virtual ~List() {}

    virtual void InsertAt(size_t index, const T& value) = 0;
    virtual void RemoveAt(size_t index) = 0;
    virtual void Clear() = 0;
    virtual bool IsEmpty() const = 0;
    virtual size_t Size() const = 0;
    virtual const T& At(size_t index) const = 0;
};
