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
        : sentinel(new Node(T())), tail(sentinel)
    {}

    ~LinkedListSentinel() override
    {
        Clear();
        delete sentinel;
    }

    void InsertAt(size_t index, const T& value) override
    {
        // TODO Throw exception if index too large -> add test first

        Node* prev = sentinel;
        for (size_t i = 0; i < index; i++)
            prev = prev->next;

        Node* newNode = new Node(value);
        newNode->next = prev->next;
        prev->next = newNode;

        if (prev == tail)
            tail = newNode;
        
        size++;
    }

    void RemoveAt(size_t index) override
    {
        if (IsEmpty())
            throw std::out_of_range("List is empty");

        Node* prev = sentinel;

        for (size_t i = 0; i < index; i++)
            prev = prev->next;
        
        Node* nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;

        if (nodeToRemove == tail)
            tail = prev;

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
        tail = sentinel;
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

        // TODO optimize: index too large check here, see LinkedListSimple

        size_t currentIndex = 0;
        Node* currentNode = sentinel->next;
        
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
    Node* tail = nullptr; // TODO refactor: can remove tail? was useful for Add, but removed it. Just remove, if tests still pass, it is fine.
    size_t size = 0;
};
