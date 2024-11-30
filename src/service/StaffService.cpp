#include "StaffService.h"

StaffService::StaffService()
{
    this->staffRepository = staffModel;
    this->invoiceRepository = invoiceModel;
    qDebug() << "Staff service initialized successfully";
}

DArray<Staff> *StaffService::getList()
{
    return this->staffRepository->getListData();
}

Staff *StaffService::find(QString id)
{
    return this->staffRepository->getDataById(id);
}

void StaffService::create(Staff data)
{
    if(data.id.length() == 0 || data.firstName.length() == 0 || data.lastName.length() == 0)
    {
        throw ValidateException::InvalidData("Field of staff must not be blank, please try again!");
    }
    this->staffRepository->insert(data);
}

void StaffService::update(Staff data)
{
    this->staffRepository->update(data);
}

void StaffService::remove(Staff data)
{
    if (!this->invoiceRepository->isStaffAvailable(data.id))
        this->staffRepository->remove(data);
}

StaffService::~StaffService()
{
}
