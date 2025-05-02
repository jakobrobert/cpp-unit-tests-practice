#pragma once

#include "List.h"

#include <stdexcept>

template <typename T>
class LinkedListWithSentinelNode : public List<T>
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
    LinkedListWithSentinelNode()
        : sentinel(new Node(T())), last(sentinel)
    {}

    ~LinkedListWithSentinelNode() override
    {
        Clear();
        delete sentinel;
    }

    void Add(const T& value) override
    {
        Node* newNode = new Node(value);
        last->next = newNode;
        last = newNode;
        size++;
    }

    void RemoveFirst() override
    {
        if (IsEmpty())
            throw std::out_of_range("List is empty");

        Node* nodeToRemove = sentinel->next;
        sentinel->next = nodeToRemove;

        if (nodeToRemove == last)
            last = sentinel;

        delete nodeToRemove;
        size--;
    }

    void Clear() override
    {
        Node* current = sentinel->next;

        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }

        sentinel->next = nullptr;
        last = sentinel;
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
        if (sentinel == nullptr)
            throw std::out_of_range("List is empty");

        size_t currentIndex = 0;
        Node* currentNode = sentinel;
        
        while (currentNode != nullptr)
        {
            if (currentIndex == index)
                return currentNode->value;

            currentNode = currentNode->next;
            currentIndex++;
        }

        throw std::out_of_range("Index is too large");
    }

private:
    Node* sentinel = nullptr;
    Node* last = nullptr;
    size_t size = 0;
};
