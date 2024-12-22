#ifndef DARRAY_H
#define DARRAY_H
#define DARRAY_DEFAULT 10000
#include <QDebug>
#include "../exception/ArraySizeException.h"
#include "../exception/DataException.h"

template <class T>
class DArray
{
private:
    T *listData = nullptr;
    size_t size;
    long capacity;

public:
    DArray()
    {
        this->capacity = DARRAY_DEFAULT;
        this->size = 0;
        this->listData = new T[this->capacity];
    }
    ~DArray()
    {

    }
    DArray(long capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->listData = new T[this->capacity];
    }
    void push(T data)
    {
        if (this->isFull())
        {
            throw ArraySizeException::ArrayFull("This dynamic array is full. Can't append any data.");
        }
        this->listData[this->size] = data;
        this->size++;
    }
    void update(T data)
    {
        for (int index = 0; index < this->getSize(); index++)
        {
            if (this->at(index) == data)
            {
                this->listData[index] = data;
                return;
            }
        }
        throw DataException::DataNotFound("Data not found!");
    }
    void popAt(T data)
    {
        if (this->isEmpty())
        {
            throw ArraySizeException::ArrayEmpty("This dynamic array is empty. Can't remove any data.");
        }
        int index = 0;
        bool foundElement = false;
        for (index = 0; index < this->getSize(); index++)
        {
            if (this->at(index) == data)
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
            this->listData[process] = this->listData[process + 1];
        }
    }
    bool isEmpty() const
    {
        return this->size == 0;
    }
    bool isFull() const
    {
        return this->size == this->capacity;
    }
    void clear() noexcept
    {
        std::destroy(this->listData, this->listData + this->size);
        this->size = 0;
    }
    size_t getSize() const
    {
        return this->size;
    }
    long getCapacity() const
    {
        return this->capacity;
    }
    T& at(int index)
    {
        return this->listData[index];
    }
};
#endif
