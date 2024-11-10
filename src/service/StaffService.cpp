#include "StaffService.h"

StaffService::StaffService()
{
    this->staffRepository = staffModel;
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
    this->staffRepository -> insert(data);
}

void StaffService::update( Staff data)
{
    this->staffRepository->update(data);
}

void StaffService::remove(Staff data)
{
    this->staffRepository->remove(data);
}

StaffService::~StaffService()
{
}
