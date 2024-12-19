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
    PointerArray<Staff> *getList();
    void push(Staff data);
    void remove(Staff data);
    void update(Staff data);
    void refresh();
    Staff *findById(QString id);
    size_t getSize();
    long getMaxStaff();
    void loadInvoiceData();
    void addInvoice(QString staffId, Invoice &data);
    void refreshInvoice();

};
#endif
