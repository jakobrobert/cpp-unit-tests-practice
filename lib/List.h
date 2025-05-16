#pragma once

template <typename T>
class List
{
public:
    virtual ~List() {}

    virtual void Add(const T& value) = 0; // TODO Remove this comment: Keep Add method to easily add at end, no need to provide index
    virtual void InsertAt(size_t index) = 0;
    virtual void RemoveFirst() = 0; // TODO Remove this method later, then just use RemoveAt(0)
    virtual void RemoveAt(size_t index) = 0;
    virtual void Clear() = 0;
    virtual bool IsEmpty() const = 0;
    virtual size_t Size() const = 0;
    virtual const T& At(size_t index) const = 0;
};
