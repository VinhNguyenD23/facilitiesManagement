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
    this->staffService->update(data);
}

void StaffController::removeStaff(Staff data)
{
    this->staffService->remove(data);
}

DArray<Staff> *StaffController::getListStaff()
{
    return this->staffService->getList();
}

Staff *StaffController::getStaffById(QString id)
{
    return this->staffService->find(id);

}

StaffController::~StaffController()
{
}
