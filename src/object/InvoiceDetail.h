#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include <QString>

struct InvoiceDetail
{
    QString facilityId;
    int quantity;
    long long price;
    double vat;
    bool operator==(InvoiceDetail &other)
    {
        return (this->facilityId == other.facilityId && this->price == other.price && this->quantity == other.quantity && this->vat == other.vat);
    }

    bool operator!=(InvoiceDetail &other)
    {
        return this->facilityId != other.facilityId;
    }
};

#endif
