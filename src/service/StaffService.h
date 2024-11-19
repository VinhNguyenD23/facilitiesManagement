#ifndef STAFFSERVICE_H
#define STAFFSERVICE_H

#include "../object/Staff.h"
#include "../datatype/DynamicArray.h"
#include "../model/GlobalModel.h"
#include <QString>
#include "../model/Staffs.h"
class StaffService
{
private:
    /* data */
    StaffsModel *staffRepository = nullptr;

public:
    StaffService(/* args */);
    DArray<Staff> *getList();
    Staff *find(QString id);
    void create(Staff data);
    void update(Staff data);
    void remove(Staff data);
    ~StaffService();
};

#endif
