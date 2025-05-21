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

    void InsertAt(size_t index, const T& value) override
    {
        // TODO Throw exception if index too large -> add test first

        Node* newNode = new Node(value);
        size++;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* prev = head;
        for (size_t i = 1; i < index; i++)
        {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }

    void RemoveAt(size_t index) override
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        // TODO Throw exception if index too large -> add test first

        size--;

        if (index == 0)
        {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
            return;
        }

        Node* prev = head;
        for (size_t i = 1; i < index; i++)
            prev = prev->next;

        Node* nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
        delete nodeToRemove;
    }

    void Clear() override
    {
        while (head != nullptr)
        {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }

        size = 0;
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

        if (index >= size)
            throw std::out_of_range("Index is too large");
        
        Node* curr = head; 
        for (size_t i = 0; i < index; i++)
            curr = curr->next;

        return curr->value;
    }

private:
    Node* head = nullptr;
    size_t size = 0;
};
