#ifndef INVOICE_H
#define INVOICE_H
#include "Date.h"
#include "InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include <QString>
struct Invoice
{
    QString id;
    Date date;
    QString staffId;
    bool type; // true: Export, false: Import
    LinkedList<InvoiceDetail> *invoiceDetailList = nullptr;
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
