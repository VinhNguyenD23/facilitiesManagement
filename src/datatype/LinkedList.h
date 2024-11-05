#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../object/Invoice.h"
#include "../object/InvoiceDetail.h"
#include "DynamicArray.h"
template <typename T>
class LinkedList
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
    void pushDataToDynamicArray(DArray<T> &data, Node *node);

public:
    LinkedList();
    ~LinkedList();
    void add(T data);
    void deleteData(T data);
    bool isEmpty() const;
    size_t getSize() const;
    Node *getData() const;
    void clear() noexcept;
    DArray<T> toDynamicArray();
};

#endif
