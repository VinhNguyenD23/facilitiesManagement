#ifndef STAFFS_H
#define STAFFS_H

#include "../datatype/DynamicArray.h"
#include "../object/Staff.h"

#define MAX_STAFF 500L

class StaffsModel
{
private:
    DArray<Staff> *data;

public:
    StaffsModel();
    DArray<Staff> *getListData();
    void insertData(Staff *data);
    void removeData(Staff *data);
    void updateData(Staff *data);
    Staff *getDataById(std::string id);
    size_t getSize();
    long getMaxStaff();
};
#endif