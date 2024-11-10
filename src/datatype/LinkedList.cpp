#include "LinkedList.h"

template <typename T>
void LinkedList<T>::pushDataToDynamicArray(DArray<T> &data, Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    data.push(node->data);
    this->pushDataToDynamicArray(data, node->next);
}

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
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

template <typename T>
void LinkedList<T>::add(T data)
{
    LinkedList<T>::Node *newNode = new LinkedList<T>::Node(data);
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
    this->size++;
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    if (this->head == nullptr)
    {
        throw std::logic_error("[ERROR] Data is empty, Can't delete");
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

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return this->head == nullptr;
}

template <typename T>
size_t LinkedList<T>::getSize() const
{
    return this->size;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::getData() const
{
    return this->head;
}

template <typename T>
void LinkedList<T>::clear() noexcept
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

template <typename T>
DArray<T> LinkedList<T>::toDynamicArray()
{
    DArray<T> dynamicData = DArray<T>();
    this->pushDataToDynamicArray(dynamicData, this->getData());
    return dynamicData;
}

template class LinkedList<Invoice>;
template class LinkedList<InvoiceDetail>;