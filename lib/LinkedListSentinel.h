#pragma once

#include "List.h"

#include <stdexcept>

template <typename T>
class LinkedListSentinel : public List<T>
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
    LinkedListSentinel()
        : sentinel(new Node(T()))
    {}

    ~LinkedListSentinel() override
    {
        Clear();
        delete sentinel;
    }

    void InsertAt(size_t index, const T& value) override
    {
        if (index > size)
            throw std::out_of_range("Index is too large");

        Node* prev = sentinel;
        for (size_t i = 0; i < index; i++)
            prev = prev->next;

        Node* newNode = new Node(value);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void RemoveAt(size_t index) override
    {
        if (IsEmpty())
            throw std::out_of_range("List is empty");

        // TODO Throw exception if index too large -> add test first

        Node* prev = sentinel;
        for (size_t i = 0; i < index; i++)
            prev = prev->next;
        
        Node* nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
        delete nodeToRemove;
        size--;
    }

    void Clear() override
    {
        while (sentinel->next != nullptr)
        {
            Node* oldSentinel = sentinel;
            sentinel = sentinel->next;
            delete oldSentinel;
        }

        size = 0;
    }

    bool IsEmpty() const override
    {
        return sentinel->next == nullptr;
    }

    size_t Size() const override
    {
        return size;
    }
    
    const T& At(size_t index) const override
    {
        if (sentinel->next == nullptr)
            throw std::out_of_range("List is empty");

        if (index >= size)
            throw std::out_of_range("Index is too large");

        Node* curr = sentinel->next; 
        for (size_t i = 0; i < index; i++)
            curr = curr->next;

        return curr->value;
    }

private:
    Node* sentinel = nullptr;
    size_t size = 0;
};
