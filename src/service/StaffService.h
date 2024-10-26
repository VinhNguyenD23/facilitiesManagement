#ifndef STAFFSERVICE_H
#define STAFFSERVICE_H

#include "../object/Staff.h"
#include "../datatype/DynamicArray.h"
#include <QString>
class StaffService
{
private:
    /* data */
public:
    StaffService(/* args */);
    DArray<Staff> getListStaff();
    Staff *findStaff(QString id);
    void createStaff(Staff staff);
    void updateStaff(QString id, Staff newData);
    void deleteStaff(QString id);
    ~StaffService();
};

#endif