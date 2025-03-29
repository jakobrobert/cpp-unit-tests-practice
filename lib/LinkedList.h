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
    // TODO add destructor & delegate to Clear()

    void Add(const T& value)
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

    void RemoveFirst()
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        size--;
    }

    void Clear()
    {
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    size_t Size() const
    {
        return size;
    }
    
    const T& At(size_t index) const
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
