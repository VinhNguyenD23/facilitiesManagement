#include "Facilities.h"
#include "../common/FilePath.h"
#include "../util/ValidateUtil.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"

void FacilitiesModel::readFile()
{
    int index = 0;
    this->data = new AVLTree<Facility, QString>();
    QFile file(FilePath::getPath(FilePath::databases::FACILITY));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("facilities");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw DatabasesException::DatabaseBroken("facilities");
        }
        Facility tempFacility;
        tempFacility.id = field.at(0);
        tempFacility.name = field.at(1);
        tempFacility.unit = field.at(2);
        tempFacility.quantity = field.at(3).toLong();
        this->data->insert(tempFacility, tempFacility.id);
        index++;
    }
    qDebug() << "Facilities Databases load:" << index;
    file.close();
}

void FacilitiesModel::writeNode(AVLTree<Facility, QString>::Node *root, QTextStream &out)
{
    if (!ValidateUtil::isNull(root))
    {
        // xuat data nut
        writeNode(root->left, out);
        out << root->data.id << ',' << root->data.name << ',' << root->data.unit << ',' << root->data.quantity << '\n';
        writeNode(root->right, out);
    }
}

void FacilitiesModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::FACILITY));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("facility");
    }
    QTextStream out(&file);
    AVLTree<Facility, QString>::Node *currentroot = this->data->getList();
    writeNode(currentroot, out);
    file.close();
}

FacilitiesModel::FacilitiesModel()
{
    this->readFile();
}

FacilitiesModel::~FacilitiesModel()
{
}

AVLTree<Facility, QString> *FacilitiesModel::getList()
{
    return this->data;
}

void FacilitiesModel::push(Facility data)
{
    if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.name) || ValidateUtil::isBlank(data.unit))
    {
        DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    }
    this->data->insert(data, data.id);
    this->writeFile();
}

void FacilitiesModel::update(Facility data)
{
    if (ValidateUtil::isNull(this->data->findIndex(data.id)))
    {
        DataException::DataNotFound("Data with id " + data.id.toStdString() + " is not existing");
    }
    if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.name) || ValidateUtil::isBlank(data.unit))
    {
        DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    }
    this->data->update(data, data.id);
    this->writeFile();
}

void FacilitiesModel::remove(QString id)
{
    if (ValidateUtil::isBlank(id))
    {
        DataException::CantHandle("Id must not be blank");
    }
    AVLTree<Facility, QString>::Node *element = this->data->findIndex(id);
    if (ValidateUtil::isNull(element))
    {
        throw DataException::DataNotFound("Data with id " + id.toStdString() + " is not existing");
    }
    this->data->remove(element->key);
    this->writeFile();
}

void FacilitiesModel::refresh()
{
    this->data->clear();
    this->readFile();
}

Facility *FacilitiesModel::findByDataId(QString id)
{
    Facility *findElement = nullptr;
    if (!ValidateUtil::isNull(this->data->findIndex(id)))
    {
        findElement = &this->data->findIndex(id)->data;
    }
    return findElement;
}
