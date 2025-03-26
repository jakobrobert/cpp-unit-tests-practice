#pragma once

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        Node(const T& value)
            : value(value), next(nullptr)
        {}

        T value;
        Node* next;
    };

public:
    // TODO fix memory leaks. remove all nodes in destructor? or use smart pointers?
    void Add(T value)
    {
        head = new Node(value);
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    size_t Size() const
    {
        if (IsEmpty())
            return 0;

        return 1;
    }
    
    T At(size_t index) const
    {
        if (IsEmpty())
            throw std::invalid_argument("Element at given index does not exist");

        return head->value;
    }

private:
    Node* head = nullptr;
};
