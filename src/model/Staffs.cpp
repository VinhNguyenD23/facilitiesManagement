#include "Staffs.h"

StaffsModel::StaffsModel()
{
    // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]

    // Read data from databases
    this->data = new DArray<Staff>(MAX_STAFF);
    QFile file("../databases/staff.csv");
    std::string line;
    QStringList field;
    if (!file.open(QIODevice::ReadOnly))
    {
        throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
        }
        Staff tempStaff;
        tempStaff.id = field.at(0);
        tempStaff.lastName = field.at(1);
        tempStaff.firstName = field.at(2);
        tempStaff.gender = (field.at(3) == QString::fromStdString("1") ? true : false);
        this->data->push(tempStaff);
    }
    for (int i = 0; i < data->getSize(); i++)
    {
        qDebug() << this->data->at(i).id << ' ' << this->data->at(i).lastName << ' ' << this->data->at(i).firstName << ' ' << this->data->at(i).gender;
    }
    file.close();
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
