#ifndef INVOICE_H
#define INVOICE_H
#include <QString>
#include "Date.h"
#include "InvoiceDetail.h"

struct Invoice
{
    QString id;
    Date date;
    bool type; // true: Export, false: Import
    InvoiceDetail *invoiceDetail = nullptr;
};

#endif