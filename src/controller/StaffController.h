#ifndef STAFFCTRL_H
#define STAFFCTRL_H
#include "../datatype/pointerarray.h"
#include "../service/StaffService.h"
#include "../object/Staff.h"
#include <QString>
#include <QDebug>

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
