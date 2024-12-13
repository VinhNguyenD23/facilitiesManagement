#include "pointerarray.h"

template <typename T>
PointerArray<T>::PointerArray()
{
    this->capacity = PARRAY_DEFAULT;
    this->size = 0;
    for (int pointerIndex = 0; pointerIndex < this->capacity; pointerIndex++)
    {
        this->PArray[pointerIndex] = nullptr;
    }
}

template <typename T>
PointerArray<T>::PointerArray(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    for (int pointerIndex = 0; pointerIndex < this->capacity; pointerIndex++)
    {
        this->PArray[pointerIndex] = nullptr;
    }
}

template <typename T>
T *PointerArray<T>::at(int index)
{
    return this->PArray[index];
}

template <typename T>
void PointerArray<T>::push(T data)
{
    if (this->isFull())
    {
        throw ArraySizeException::ArrayFull("This dynamic array is full. Can't append any data.");
    }
    T *pushData = new T(data);
    this->PArray[this->size++] = pushData;
}

template <typename T>
void PointerArray<T>::remove(T data)
{
    if (this->isEmpty())
    {
        throw ArraySizeException::ArrayEmpty("This dynamic array is empty. Can't remove any data.");
    }
    int index = 0;
    bool foundElement = false;
    for (index = 0; index < this->getSize(); index++)
    {
        if (*this->at(index) == data)
        {
            foundElement = true;
            break;
        }
    }

    if (!foundElement)
    {
        throw DataException::DataNotFound("Element not found!");
    }

    this->size--;
    for (int process = index; process < this->getSize(); process++)
    {
        this->PArray[process] = this->PArray[process + 1];
    }
}

template <typename T>
void PointerArray<T>::update(T data)
{
    for (int index = 0; index < this->getSize(); index++)
    {
        if (*this->at(index) == data)
        {
            this->PArray[index] = new T(data);
            return;
        }
    }
    throw DataException::DataNotFound("Data not found!");
}

template <typename T>
bool PointerArray<T>::isFull() const
{
    return (this->size == this->capacity);
}

template <typename T>
bool PointerArray<T>::isEmpty() const
{
    return (this->size == 0);
}

template <typename T>
void PointerArray<T>::clear() noexcept
{
    for (int index = 0; index < this->size; index++)
    {
        delete PArray[index];
        PArray[index] = nullptr;
    }
}

template <typename T>
size_t PointerArray<T>::getSize() const
{
    return this->size;
}

template <typename T>
int PointerArray<T>::getCapacity() const
{
    return this->capacity;
}

template class PointerArray<Staff>;
template class PointerArray<Facility>;
template class PointerArray<Invoice>;
template class PointerArray<InvoiceDetail>;
template class PointerArray<std::string>;
