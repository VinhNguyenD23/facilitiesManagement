#include "StaffService.h"
#include "../model/GlobalModel.h"
#include "../exception/DataException.h"
#include "../util/ValidateUtil.h"
#include "../exception/ValidateException.h"
StaffService::StaffService()
{
    this->staffRepository = staffModel;
    this->invoiceRepository = invoiceModel;
}

PointerArray<Staff> *StaffService::getList()
{
    return this->staffRepository->getList();
}

Staff *StaffService::find(QString id)
{
    auto *data = this->staffRepository->findById(id);
    if(ValidateUtil::isNull(data))
    {
        throw DataException::DataNotFound(id.toStdString() + " not found");
    }
    return data;
}

void StaffService::create(Staff data)
{
    if(data.id.length() == 0 || data.firstName.length() == 0 || data.lastName.length() == 0)
    {
        throw ValidateException::InvalidData("Field of staff must not be blank, please try again!");
    }
    this->staffRepository->push(data);
}

void StaffService::update(Staff data)
{
    this->staffRepository->update(data);
}

void StaffService::remove(Staff data)
{
    auto *getListInvoices = this->staffRepository->findById(data.id)->invoicesList;
    if(!ValidateUtil::isNull(getListInvoices) && !getListInvoices->isEmpty())
    {
        throw DataException::ExistDataId("Staff is already in the invoice, cannot delete staff.");
    }

    this->staffRepository->remove(data);
}

StaffService::~StaffService()
{
}
