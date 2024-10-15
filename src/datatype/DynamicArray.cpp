#include "DynamicArray.h"

template <class T>
inline DArray<T>::DArray()
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
inline DArray<T>::DArray(long capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->listData = new T[this->capacity];
}

template <class T>
void DArray<T>::push(T *data)
{
    if (this->isFull())
    {
        throw std::overflow_error("[ERROR] This dynamic array is full. Can't append any element.");
    }
    this->listData[this->size] = data;
    this->size++;
}

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

template <class T>
void DArray<T>::popAt(T *data)
{
}

template <class T>
inline bool DArray<T>::isEmpty() const
{
    return this->size == 0;
}

template <class T>
inline bool DArray<T>::isFull() const
{
    return this->size == this->capacity;
}

template <class T>
inline void DArray<T>::clear() noexcept
{
    std::destroy(this->listData, this->listData + this->size);
    this->size = 0;
}

template <class T>
inline size_t DArray<T>::getSize() const
{
    return this->size;
}

template <class T>
inline long DArray<T>::getCapacity() const
{
    return this->capacity;
}
