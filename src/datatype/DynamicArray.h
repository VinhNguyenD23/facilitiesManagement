#ifndef DARRAY_H
#define DARRAY_H
#define DEFAULT INT_MAX
#include <iostream>

template <class T>
class DArray
{
private:
    T *listData;
    size_t size;
    long capacity;

public:
    DArray();
    ~DArray();
    DArray(long capacity);
    void push(T *data);
    // void pushFront(T *data);
    // void pushAt(size_t index, T *data);
    void popAt(T *data);
    bool isEmpty() const;
    bool isFull() const;
    void clear() noexcept;
    size_t getSize() const;
    long getCapacity() const;
};
#endif