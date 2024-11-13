#include "Staffs.h"

void StaffsModel::readFile()
{
    this->data = new DArray<Staff>(MAX_STAFF);
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
        tempStaff.gender = (field.at(3) == QString::fromStdString("1") ? true : false);
        this->insert(tempStaff);
    }
    for (int i = 0; i < data->getSize(); i++)
    {
        qDebug() << this->data->at(i).id << ' ' << this->data->at(i).lastName << ' ' << this->data->at(i).firstName << ' ' << this->data->at(i).gender;
    }
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
    auto *ds = this->getListData;
    for ( int i = 0; i < ds->getsize(); i++) {
        out << ds->data->at(i).id << ' ' << ds->data->at(i).lastName << ' ' << ds->data->at(i).firstName << ' ' << ds->data->at(i).gender;
    }
    file.close();
}

StaffsModel::StaffsModel()
{
    this->readFile();
}

StaffsModel::~StaffsModel()
{
    this->data->clear();
}

DArray<Staff> *StaffsModel::getListData()
{
    return this->data;
}

void StaffsModel::insert(Staff data)
{
    this->data->push(data);
}

void StaffsModel::remove(Staff data)
{
    // TODO: Code remove function for list staffs [ priority: above normal ] [Testing]
    this->data->popAt(data);
}

void StaffsModel::update(Staff data)
{
    // TODO: Code update function for list staffs [ priority: above normal ] [TODO]
    this->data->push(data);
}

void StaffsModel::refresh()
{
    this->data->clear();
    this->readFile();
}

Staff *StaffsModel::getDataById(QString id)
{
    // TODO: Code get data by id object [ priority: above normal ] [TESTING]
    Staff *findData = nullptr;
    for (int i = 0; i < this->getSize(); i++)
    {
        if (id == this->data->at(i).id)
        {
            Staff temp = this->data->at(i);
            findData = &temp;
        }
    }
    return findData;
}

size_t StaffsModel::getSize()
{
    return this->data->getSize();
}

long StaffsModel::getMaxStaff()
{
    return MAX_STAFF;
}
