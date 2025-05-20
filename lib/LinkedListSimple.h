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
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void InsertAt(size_t index, const T& value) override
    {
        // TODO exception for index > size. add test first.

        Node* newNode = new Node(value);
        size++;

        // TODO remove debug code

        if (head == nullptr)
        {
            std::cout << "insert into empty list" << std::endl;
            head = tail = newNode;
            return;
        }

        if (index == 0)
        {
            std::cout << "insert at beginning" << std::endl;
            newNode->next = head;
            head = newNode;
            return;
        }

        if (index == size - 1) // -1 because checking old size, before increment
        {
            std::cout << "insert at end" << std::endl;
            tail->next = newNode;
            tail = newNode;
            return;
        }

        std::cout << "insert at middle" << std::endl;

        Node* prev = head;

        for (size_t i = 1; i < index; i++)
        {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
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

    void RemoveAt(size_t index) override
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        size--;

        if (index == 0)
        {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;

            if (head == nullptr)
                tail = nullptr;

            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }

        delete tail;
        prev->next = nullptr;
        tail = prev;
    }

    void Clear() override
    {
        // TODO optimize: can inline, currently additional head == nullptr check done in each RemoveFirst call, but is already done by IsEmpty.
        //  -> as well, no need to dec size each step, just size = 0 at end
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
    Node* tail = nullptr;
    size_t size = 0;
};
