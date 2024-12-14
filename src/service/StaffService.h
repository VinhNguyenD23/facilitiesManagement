#ifndef STAFFSERVICE_H
#define STAFFSERVICE_H

#include "../object/Staff.h"
#include "../model/Staffs.h"
#include "../model/Invoices.h"
#include "../datatype/pointerarray.h"
#include <QString>

class StaffService
{
private:
    /* data */
    StaffsModel *staffRepository = nullptr;
    InvoiceModel *invoiceRepository = nullptr;

public:
    StaffService(/* args */);
    PointerArray<Staff> *getList();
    Staff *find(QString id);
    void create(Staff data);
    void update(Staff data);
    void remove(Staff data);
    ~StaffService();
};

#endif
