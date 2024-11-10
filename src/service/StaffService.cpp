#include "StaffService.h"

StaffService::StaffService()
{
    this->staffRepository = staffModel;
}

void StaffService::create(Staff data)
{
    this->staffRepository->insertData(data);
}

DArray<Staff> *StaffService::readAll()
{
    return this->staffRepository->getListData();
}

Staff *StaffService::readById(QString id)
{
    Staff *StaffDetail = this->staffRepository->getDataById(id);
    if (StaffDetail == nullptr)
    {
        throw DataException::DataNotFound("Not found any Staff with Staff id: " + id.toStdString());
    }
    return StaffDetail;
}

void StaffService::update(Staff data)
{
    if (this->staffRepository->getDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any Staff with Staff id: " + data.id.toStdString());
    }
    this->staffRepository->updateData(data);
}

void StaffService::remove(Staff data)
{
    if (this->staffRepository->getDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any Staff with Staff id: " + data.id.toStdString());
    }
    this->staffRepository->removeData(data);
}

DArray<Staff> StaffService::getList()
{
    return DArray<Staff>();
}

Staff *StaffService::find(QString id)
{
    return nullptr;
}

void StaffService::create(Staff staff)
{
}

void StaffService::update(QString id, Staff newData)
{
}

void StaffService::remove(QString id)
{
}

StaffService::~StaffService()
{
}
