#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../exception/ArraySizeException.h"
#include <QDebug>

template <typename T>
class LinkedList
{
public:
    struct Node
    {
        T &data;
        Node *next;
        Node(T &data) : data(data)
        {
            // this->data = &data;
            this->next = nullptr;
        };
    };

private:
    Node *head;
    size_t size;

public:
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList()
    {
        this->size = 0;
        LinkedList<T>::Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            LinkedList<T>::Node *temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }

    void add(T &data)
    {
        this->size++;
        LinkedList<T>::Node *newNode = new LinkedList<T>::Node(data);
        qDebug() << "Clone address:" << &data << &newNode->data;
        if (this->head == nullptr)
        {
            this->head = newNode;
            return;
        }
        LinkedList<T>::Node *currentNode = this->head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    void remove(T data)
    {
        if (this->head == nullptr)
        {
            throw ArraySizeException::ArrayEmpty("List is empty, Can't delete");
        }
        if (this->head->data == data)
        {
            LinkedList<T>::Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }

        LinkedList<T>::Node *currentNode = this->head;
        while (currentNode->next != nullptr && currentNode->next->data != data)
        {
            currentNode = currentNode->next;
        }

        if (currentNode->next != nullptr)
        {
            LinkedList<T>::Node *temp = currentNode->next;
            currentNode->next = temp->next;
            delete temp;
            return;
        }
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    size_t getSize() const
    {
        return this->size;
    }

    Node *getList() const
    {
        return this->head;
    }

    void clear() noexcept
    {
        this->size = 0;
        LinkedList<T>::Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            LinkedList<T>::Node *temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
        this->head = nullptr;
    }

    Node *getElement(T data)
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            if (current->data == data)
                return current;
            current = current->next;
        }
        return nullptr;
    }
};

#endif
