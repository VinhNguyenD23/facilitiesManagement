#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include <QString>

struct InvoiceDetail
{
    QString facilityId;
    int quantity;
    long long price;
    double vat;
    // bool operator==(InvoiceDetail &other)
    // {
    //     return this->id == other.id;
    // }

    // bool operator!=(InvoiceDetail &other)
    // {
    //     return this->id != other.id;
    // }
};

#endif
