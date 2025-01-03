#ifndef STAFF_H
#define STAFF_H

#include "Invoice.h"
#include <QString>

struct Staff
{
    QString id; // Example: QL00X, TN00Y, BH00Z, TV00A
    QString firstName;
    QString lastName;
    bool gender;
    LinkedList<Invoice> *invoicesList = nullptr;
    bool operator==(Staff &other)
    {
        return this->id == other.id;
    }

    bool operator!=(Staff &other)
    {
        return this->id != other.id;
    }
};

#endif
