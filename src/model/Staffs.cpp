#include "Staffs.h"

StaffsModel::StaffsModel()
{
    this->data = new DArray<Staff>[MAX_STAFF];
}

DArray<Staff> *StaffsModel::getListData()
{
    return this->data;
}

void StaffsModel::insertData(Staff *data)
{
    this->data->push(data);
}

void StaffsModel::removeData(Staff *data)
{
    // TODO: Code remove function for list staffs [ priority: above normal ]
}

void StaffsModel::updateData(Staff *data)
{
    // TODO: Code update function for list staffs [ priority: above normal ]
}

Staff *StaffsModel::getDataById(std::string id)
{
    // TODO: Code get data by id object [ priority: above normal ]
    return nullptr;
}

size_t StaffsModel::getSize()
{
    return this->data->getSize();
}

long StaffsModel::getMaxStaff()
{
    return MAX_STAFF;
}
