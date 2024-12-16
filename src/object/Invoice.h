#ifndef INVOICE_H
#define INVOICE_H
#include <QString>
#include "../datatype/LinkedList.h"
#include "InvoiceDetail.h"
#include "Date.h"
struct Invoice
{
    QString id;
    Date date;
    QString staffId;
    bool type; // true: Import, false: Export
    LinkedList<InvoiceDetail> *invoiceDetailList;
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
