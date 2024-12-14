#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#define PARRAY_DEFAULT 10000

#include "../exception/ArraySizeException.h"
#include "../exception/DataException.h"

template<typename T>
class PointerArray
{
private:
    T *PArray[PARRAY_DEFAULT];
    size_t size;
    int capacity;

public:
    PointerArray()
    {
        this->capacity = PARRAY_DEFAULT;
        this->size = 0;
        for (int pointerIndex = 0; pointerIndex < this->capacity; pointerIndex++)
        {
            this->PArray[pointerIndex] = nullptr;
        }
    }
    PointerArray(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        for (int pointerIndex = 0; pointerIndex < this->capacity; pointerIndex++)
        {
            this->PArray[pointerIndex] = nullptr;
        }
    }
    T *at(int index)
    {
        return this->PArray[index];
    }
    void push(T data)
    {
        if (this->isFull())
        {
            throw ArraySizeException::ArrayFull("This dynamic array is full. Can't append any data.");
        }
        T *pushData = new T(data);
        this->PArray[this->size++] = pushData;
    }
    void remove(T data)
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
    void update(T data)
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
    bool isFull() const
    {
        return (this->size == this->capacity);
    }
    bool isEmpty() const
    {
        return (this->size == 0);
    }
    void clear() noexcept
    {
        for (int index = 0; index < this->size; index++)
        {
            delete PArray[index];
            PArray[index] = nullptr;
        }
    }
    size_t getSize() const
    {
        return this->size;
    }
    int getCapacity() const
    {
        return this->capacity;
    }
    // void resize();
};

#endif // POINTERARRAY_H
