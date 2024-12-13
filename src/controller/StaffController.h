#ifndef STAFFCTRL_H
#define STAFFCTRL_H
#include "../service/StaffService.h"
#include <QString>
#include <QDebug>
#include "../datatype/pointerarray.h"
#include "../object/Staff.h"

class StaffController
{
private:
    /* data */
    StaffService *staffService = nullptr;

public:
    StaffController(/* args */);
    void create(Staff data);
    void updateExistStaff(Staff data);
    void removeStaff(Staff data);
    PointerArray<Staff> *getListStaff();
    Staff *getStaffById(QString id);
    ~StaffController();
};

#endif
