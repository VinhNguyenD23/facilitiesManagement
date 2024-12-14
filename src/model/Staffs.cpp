#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../util/ArrayUtil.h"
#include "Staffs.h"

void StaffsModel::readFile()
{
    this->data = new PointerArray<Staff>(MAX_STAFF);
    QFile file(FilePath::getPath(FilePath::databases::STAFF));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("staff");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw DatabasesException::DatabaseBroken("staff");
        }
        Staff tempStaff;
        tempStaff.id = field.at(0);
        tempStaff.lastName = field.at(1);
        tempStaff.firstName = field.at(2);
        tempStaff.gender = (field.at(3).contains("1") ? true : false);
        this->insert(tempStaff);
    }
    // for (int i = 0; i < data->getSize(); i++)
    // {
    //     qDebug() << this->data->at(i).id << ' ' << this->data->at(i).lastName << ' ' << this->data->at(i).firstName << ' ' << this->data->at(i).gender;
    // }
    qDebug() << "Staff Databases load: " << this->getSize();

    file.close();
}
void StaffsModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::STAFF));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("staff");
    }
    QTextStream out(&file);
    auto *current = this->getListData();
    // qDebug() << current->getSize();
    for (int i = 0; i < current->getSize(); i++)
    {
        Staff *data = current->at(i);
        out << data->id << ',' << data->lastName << ',' << data->firstName << ',' << data->gender << '\n';
    }
    file.close();
}

StaffsModel::StaffsModel()
{
    qDebug() << "Staff model initialized successfully";
    this->readFile();
}

StaffsModel::~StaffsModel()
{
    this->data->clear();
}

PointerArray<Staff> *StaffsModel::getListData()
{
    return this->data;
}

void StaffsModel::insert(Staff data)
{
    if(this->getDataById(data.id) != nullptr)
    {
        throw DataException::DuplicateDataId("Staff id is existing, please try other id!");
    }
    this->data->push(data);
    ArrayUtil<Staff>::StaffSort(this->getListData());
    this->writeFile();
}

void StaffsModel::remove(Staff data)
{
    // TODO: Code remove function for list staffs [ priority: above normal ] [Rewrite]
    // QFile file(FilePath::getPath(FilePath::databases::STAFF));
    // if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    // {
    //     throw std::runtime_error("[ERROR] This database (staff) not found or broken, please try again !");
    //     // throw DatabasesException::DatabaseBroken("staff");
    // }
    // QTextStream outData(&file);
    // for (int i = 0; i < this->getSize(); i++)
    // {
    //     if (data.id != this->data->at(i).id)
    //     {
    //         outData << this->data->at(i).id << ',' << this->data->at(i).lastName << ',' << this->data->at(i).firstName << ',' << this->data->at(i).gender << '\n';
    //     }
    // }
    // file.close();
    this->data->remove(data);
    this->writeFile();
}

void StaffsModel::update(Staff data)
{
    // TODO: Code update function for list staffs [ priority: above normal ] [TODO]
    this->data->update(data);
    this->writeFile();
}

void StaffsModel::refresh()
{
    this->data->clear();
    this->readFile();
}

Staff *StaffsModel::getDataById(QString id)
{
    // TODO: Code get data by id object [ priority: above normal ] [TESTING]
    // Staff *findData = nullptr;
    for (int i = 0; i < this->getSize(); i++)
    {
        if (id == this->data->at(i)->id)
        {
            return this->data->at(i);
        }
    }
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
