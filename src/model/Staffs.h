#ifndef STAFFS_H
#define STAFFS_H

#include "../datatype/DynamicArray.h"
#include "../object/Staff.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QMessageBox>

#define MAX_STAFF 500L

class StaffsModel
{
private:
    DArray<Staff> *data;

public:
    StaffsModel();
    ~StaffsModel();
    DArray<Staff> *getListData();
    void insertData(Staff data);
    void removeData(Staff data);
    void updateData(Staff data);
    void refreshData();
    Staff *getDataById(QString id);
    size_t getSize();
    long getMaxStaff();
};
#endif
