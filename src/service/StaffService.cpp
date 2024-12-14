#include "StaffService.h"
#include "../model/GlobalModel.h"
#include "../exception/DataException.h"
#include "../exception/ValidateException.h"
StaffService::StaffService()
{
    this->staffRepository = staffModel;
    this->invoiceRepository = invoiceModel;
    qDebug() << "Staff service initialized successfully";
}

PointerArray<Staff> *StaffService::getList()
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
    if (this->invoiceRepository->isStaffAvailable(data.id))
    {
        throw DataException::ExistDataId("Staff is already in the invoice, cannot delete staff.");
    }
    this->staffRepository->remove(data);
}

StaffService::~StaffService()
{
}
