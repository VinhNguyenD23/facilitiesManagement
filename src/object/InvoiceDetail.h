#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include <QString>
#include "Facility.h"

struct InvoiceDetail
{
    QString id;
    QString facilityId;
    Facility *facility = nullptr;
    int quantity;
    double price;
    double vat;
};

#endif