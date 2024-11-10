#include "StaffController.h"

StaffController::StaffController()
{
    this->staffService = new StaffService();
}

void StaffController::create(Staff data)
{
    this->staffService->create(data);
}

void StaffController::updateExistStaff(Staff data)
{
    this->StaffService->update(data);
}

void StaffController::removeStaff(Staff data)
{
    this->StaffService->remove(data);
}

DArray<Staff> *StaffController::getListStaff()
{
    return nullptr;
}

Staff *StaffController::getStaffById(QString id)
{
    return nullptr;

}

StaffController::~StaffController()
{
}
