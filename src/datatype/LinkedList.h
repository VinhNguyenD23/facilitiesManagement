#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../exception/ArraySizeException.h"
#include "../util/ValidateUtil.h"
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
        while (!ValidateUtil::isNull(currentNode->next))
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
        if (ValidateUtil::isNull(this->head))
        {
            this->head = newNode;
            return;
        }
        LinkedList<T>::Node *currentNode = this->head;
        while (!ValidateUtil::isNull(currentNode->next))
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    void remove(T data)
    {
        if (ValidateUtil::isNull(this->head))
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
        while (!ValidateUtil::isNull(currentNode->next) && currentNode->next->data != data)
        {
            currentNode = currentNode->next;
        }

        if (!ValidateUtil::isNull(currentNode->next))
        {
            LinkedList<T>::Node *temp = currentNode->next;
            currentNode->next = temp->next;
            delete temp;
            return;
        }
    }

    bool isEmpty() const
    {
        return ValidateUtil::isNull(this->head);
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
        while (!ValidateUtil::isNull(currentNode->next))
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
        while (!ValidateUtil::isNull(current))
        {
            if (current->data == data)
                return current;
            current = current->next;
        }
        return nullptr;
    }
};

#endif
