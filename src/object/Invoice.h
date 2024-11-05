#ifndef INVOICE_H
#define INVOICE_H
#include <QString>
#include "Date.h"
struct Invoice
{
    QString id;
    Date date;
    QString staffId;
    bool type; // true: Export, false: Import
    bool operator==(Invoice &other)
    {
        return this->id == other.id;
    }

    bool operator!=(Invoice &other)
    {
        return this->id != other.id;
    }
};

#endif