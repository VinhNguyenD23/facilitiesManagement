#include "LinkedList.h"

template <typename T>
linkedList<T>::linkedList()
{
    this->head = nullptr;
}

template <typename T>
linkedList<T>::~linkedList()
{
    this->size = 0;
    linkedList<T>::Node *currentNode = head;
    while (currentNode->next != nullptr)
    {
        linkedList<T>::Node *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
}

template <typename T>
void linkedList<T>::add(T data)
{
    linkedList<T>::Node *newNode = new linkedList<T>::Node(data);
    if (this->head == nullptr)
    {
        this->head = newNode;
        return;
    }
    linkedList<T>::Node *currentNode = this->head;
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    this->size++;
}

template <typename T>
void linkedList<T>::deleteData(T data)
{
    if (this->head == nullptr)
    {
        throw new std::runtime_error("[ERROR] Data is empty, Can't delete");
    }
    if (this->head->data == data)
    {
        linkedList<T>::Node temp = this->head;
        this->head = this->head->next;
        delete temp;
        return;
    }

    linkedList<T>::Node *currentNode = this->head;
    while (currentNode->next != nullptr && currentNode->next->data != data)
    {
        currentNode = currentNode->next;
    }

    if (currentNode->next != nullptr)
    {
        linkedList<T>::Node *temp = currentNode->next;
        currentNode->next = temp->next;
        delete temp;
        return;
    }
}

template <typename T>
bool linkedList<T>::isEmpty() const
{
    return this->head == nullptr;
}

template <typename T>
size_t linkedList<T>::getSize() const
{
    return this->size;
}

template <typename T>
typename linkedList<T>::Node *linkedList<T>::getData() const
{
    return this->head;
}

template <typename T>
void linkedList<T>::clear() noexcept
{
    this->size = 0;
    linkedList<T>::Node *currentNode = head;
    while (currentNode->next != nullptr)
    {
        linkedList<T>::Node *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    this->head = nullptr;
}
