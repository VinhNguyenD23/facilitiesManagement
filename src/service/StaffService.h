#ifndef STAFFSERVICE_H
#define STAFFSERVICE_H

#include "../object/Staff.h"
#include "../datatype/DynamicArray.h"
#include <QString>
class StaffService
{
private:
    /* data */
    StaffsModel *staffRepository = nullptr;
public:
    StaffService(/* args */);
    DArray<Staff> getList();
    Staff *find(QString id);
    void create(Staff staff);
    void update(QString id, Staff newData);
    void remove(QString id);
    ~StaffService();
};

#endif