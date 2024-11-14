#include "DynamicArray.h"

template <class T>
DArray<T>::DArray()
{
    this->capacity = DEFAULT;
    this->size = 0;
    this->listData = new T[this->capacity];
}

template <class T>
DArray<T>::~DArray()
{
}

template <class T>
DArray<T>::DArray(long capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->listData = new T[this->capacity];
}

template <class T>
void DArray<T>::push(T data)
{
    if (this->isFull())
    {
        throw ArraySizeException::ArrayFull("This dynamic array is full. Can't append any data.");
        // throw std::overflow_error("[ERROR] This dynamic array is full. Can't append any element.");
    }
    this->listData[this->size] = data;
    this->size++;
}

#pragma region unused
// template <class T>
// void DArray<T>::pushFront(T *data)
// {
//     if (this->isFull())
//     {
//         throw std::overflow_error("[ERROR] This dynamic array is full. Can't append any element.");
//     }
//     for (size_t i = this->size; i > 0; i--)
//     {
//         this->listData[i] = this->listData[i - 1];
//     }
//     this->listData[0] = data;
// }

// template <class T>
// void DArray<T>::pushAt(size_t index, T *data)
// {
//     if (this->isFull())
//     {
//         throw std::overflow_error("[ERROR] This dynamic array is full. Can't append any element.");
//     }
//     if (index >= size)
//     {
//         throw std::logic_error("[ERROR] index of new data can't higher than this array size.");
//     }
//     for (size_t i = this->size; i > index; i--)
//     {
//         this->listData[i] = this->listData[i - 1];
//     }
//     this->listData[index] = data;
// }
#pragma endregion

template <class T>
void DArray<T>::popAt(T data)
{
    if (this->isEmpty())
    {
        throw ArraySizeException::ArrayEmpty("This dynamic array is empty. Can't remove any data.");
        // throw std::logic_error("[ERROR] This dynamic array is empty. Can't remove any data.");
    }
}

template <class T>
bool DArray<T>::isEmpty() const
{
    return this->size == 0;
}

template <class T>
bool DArray<T>::isFull() const
{
    return this->size == this->capacity;
}

template <class T>
void DArray<T>::clear() noexcept
{
    std::destroy(this->listData, this->listData + this->size);
    this->size = 0;
}

template <class T>
size_t DArray<T>::getSize() const
{
    return this->size;
}

template <class T>
long DArray<T>::getCapacity() const
{
    return this->capacity;
}

template <class T>
T DArray<T>::at(int index)
{
    return this->listData[index];
}

template class DArray<Staff>;
template class DArray<Facility>;
template class DArray<Invoice>;
template class DArray<InvoiceDetail>;
template class DArray<std::string>;