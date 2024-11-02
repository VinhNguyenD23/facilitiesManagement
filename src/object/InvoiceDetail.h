#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include <QString>
#include "Facility.h"

struct InvoiceDetail
{
    QString id;
    QString invoiceId;
    QString facilityId;
    int quantity;
    long price;
    double vat;
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