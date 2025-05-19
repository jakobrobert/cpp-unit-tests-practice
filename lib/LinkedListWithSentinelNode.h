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
        : sentinel(new Node(T())), tail(sentinel)
    {}

    ~LinkedListWithSentinelNode() override
    {
        Clear();
        delete sentinel;
    }

    void Add(const T& value) override
    {
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void InsertAt(size_t index, const T& value) override
    {
        Node* newNode = new Node(value);
        size++;
        
        if (index == 0)
        {
            newNode->next = sentinel->next;
            sentinel->next = newNode;

            if (tail == sentinel)
                tail = newNode;

            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void RemoveFirst() override
    {
        if (IsEmpty())
            throw std::out_of_range("List is empty");

        Node* nodeToRemove = sentinel->next;
        sentinel->next = nodeToRemove->next;

        if (nodeToRemove == tail)
            tail = sentinel;

        delete nodeToRemove;
        size--;
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

        size_t currentIndex = 0;
        Node* currentNode = sentinel->next;
        
        while (currentNode != nullptr)
        {
            // TODO Optimize: No need to do this index check, can just move next pointer in for loop, iterating by index
            if (currentIndex == index)
                return currentNode->value;

            currentNode = currentNode->next;
            currentIndex++;
        }

        // TODO Optimize: Do check index >= size in beginning. same in LinkedListSimple
        throw std::out_of_range("Index is too large");
    }

private:
    Node* sentinel = nullptr;
    Node* tail = nullptr;
    size_t size = 0;
};
