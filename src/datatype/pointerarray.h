#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#define PARRAY_DEFAULT 10000

#include <ios>

#include "../object/Staff.h"
#include "../object/Facility.h"
#include "../object/Invoice.h"
#include "../object/InvoiceDetail.h"

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
    PointerArray();
    PointerArray(int capacity);
    T *at(int index);
    void push(T data);
    void remove(T data);
    void update(T data);
    bool isFull() const;
    bool isEmpty() const;
    void clear() noexcept;
    size_t getSize() const;
    int getCapacity() const;
};

#endif // POINTERARRAY_H
