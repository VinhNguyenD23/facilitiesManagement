#ifndef STAFFS_H
#define STAFFS_H

#include "../datatype/pointerarray.h"
#include "../common/FilePath.h"
#include "../object/Staff.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QMessageBox>

#define MAX_STAFF 500L

class StaffsModel
{
private:
    PointerArray<Staff> *data;

private:
    void readFile();
    void writeFile();

public:
    StaffsModel();
    ~StaffsModel();
    PointerArray<Staff> *getListData();
    void insert(Staff data);
    void remove(Staff data);
    void update(Staff data);
    void refresh();
    Staff *getDataById(QString id);
    size_t getSize();
    long getMaxStaff();
};
#endif
