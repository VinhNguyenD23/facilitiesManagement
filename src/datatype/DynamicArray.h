#ifndef DARRAY_H
#define DARRAY_H
#define DEFAULT 10000
#include <iostream>
#include "../object/Staff.h"
#include "../object/Facility.h"
#include "../object/Invoice.h"
#include "../object/InvoiceDetail.h"

template <class T>
class DArray
{
private:
    T *listData = nullptr;
    size_t size;
    long capacity;

public:
    DArray();
    ~DArray();
    DArray(long capacity);
    void push(T data);
    // void pushFront(T *data);
    // void pushAt(size_t index, T *data);
    void popAt(T *data);
    bool isEmpty() const;
    bool isFull() const;
    void clear() noexcept;
    size_t getSize() const;
    long getCapacity() const;
    T at(int index);
};
#endif
