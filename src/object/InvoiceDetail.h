#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include <QString>

struct InvoiceDetail
{
    QString id;
    QString invoiceId;
    QString facilityId;
    int quantity;
    long price;
    double vat;
    bool operator==(InvoiceDetail &other)
    {
        return this->id == other.id;
    }

    bool operator!=(InvoiceDetail &other)
    {
        return this->id != other.id;
    }
};

#endif
