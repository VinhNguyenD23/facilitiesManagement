#ifndef INVOICE_H
#define INVOICE_H
#include <QString>
#include "Date.h"
#include "InvoiceDetail.h"
struct Invoice
{
    QString id;
    Date date;
    QString staffId;
    bool type; // true: Export, false: Import

    InvoiceDetail *invoiceDetail = nullptr;
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