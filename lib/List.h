#pragma once

template <typename T>
class List
{
public:
    virtual ~List()
    {
        Clear();
    }

    virtual void Add(const T& value) = 0;
    virtual void RemoveFirst() = 0;
    virtual void Clear() = 0;
    virtual bool IsEmpty() const = 0;
    virtual size_t Size() const = 0;
    virtual const T& At(size_t index) const = 0;
};
