#include "Staffs.h"

StaffsModel::StaffsModel()
{
    this->data = new DArray<Staff>[MAX_STAFF];
    // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]
    std::fstream f("../databases/staff.csv", std::ios::in | std::ios::out);
    std::string line;
    if(f.is_open())
    {
        while (getline(f, line))
        {
            std::istringstream fileData(line);
            std::string tempData;
            Staff getUser;
            DArray<std::string> staff;
            // while (getline(fileData, tempData, ','))
            // {
            //     temp.push(tempData);
            // }
            // std::cout << std::endl;
            std::string genderStr;
            std::getline(fileData, getUser.id, ',');
            std::getline(fileData, getUser.firstName, ',');
            std::getline(fileData, getUser.lastName, ',');
            std::getline(fileData, genderStr, ',');

            getUser.gender = (genderStr == "1"); // Chuyển chuỗi giới tính thành kiểu bool

            staff.push(getUser);
    }
    f.clone();
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
