#include "Staffs.h"

StaffsModel::StaffsModel()
{
    // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]

    // Read data from databases
    this->data = new DArray<Staff>(MAX_STAFF);
    std::fstream f("../databases/staff.csv", std::ios::in | std::ios::out);
    std::string line;
    if(f.is_open())
    {
        while (getline(f, line))
        {
            std::istringstream fileData(line);
            std::string tempData;
            Staff getUser;
            DArray<std::string> temp;
            while (getline(fileData, tempData, ','))
            {
                temp.push(tempData);
            }
            std::cout << std::endl;
        }
    }
    else
    {
        throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
}

StaffsModel::~StaffsModel()
{
}

DArray<Staff> *StaffsModel::getListData()
{
    return this->data;
}

void StaffsModel::insertData(Staff data)
{
    this->data->push(data);
}

void StaffsModel::removeData(Staff data)
{
    // TODO: Code remove function for list staffs [ priority: above normal ]
}

void StaffsModel::updateData(Staff data)
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
