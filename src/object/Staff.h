#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <QString>
#include "Invoice.h"

struct Staff
{
    QString id; // Example: QL00X, TN00Y, BH00Z, TV00A
    QString firstName;
    QString lastName;
    bool gender;
    Invoice **invoices = nullptr;
};

#endif
