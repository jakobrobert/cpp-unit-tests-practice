#pragma once

#include "List.h"

#include <stdexcept>

template <typename T>
class LinkedListSimple : public List<T>
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
    ~LinkedListSimple() override
    {
        Clear();
    }

    void Add(const T& value) override
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        size++;
    }

    void RemoveFirst() override
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        size--;
    }

    void Clear() override
    {
        while (!IsEmpty())
            RemoveFirst();
    }

    bool IsEmpty() const override
    {
        return head == nullptr;
    }

    size_t Size() const override
    {
        return size;
    }
    
    const T& At(size_t index) const override
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        size_t currentIndex = 0;
        Node* currentNode = head;
        
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
    Node* head = nullptr;
    Node* last = nullptr;
    size_t size = 0;
};
