#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class linkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        };
    };

private:
    Node *head;
    size_t size;

public:
    linkedList();
    ~linkedList();
    void add(T data);
    void deleteData(T data);
    bool isEmpty() const;
    size_t getSize() const;
    Node *getData() const;
    void clear() noexcept;
};

#endif
