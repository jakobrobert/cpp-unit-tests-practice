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
            last = newNode; // TODO do tests still pass if this line is removed?
        }

        size++;
    }

    void RemoveFirst()
    {
        size--;

        if (head == nullptr)
            return;

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
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
