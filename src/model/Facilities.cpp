#include "Facilities.h"

void FacilitiesModel::readFile()
{
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
    }
    DArray<Facility> toDynamicArray = this->data->toDynamicArray();
    for (int i = 0; i < toDynamicArray.getSize(); i++)
    {
        qDebug() << toDynamicArray.at(i).id + ' ' + toDynamicArray.at(i).name + ' ' + toDynamicArray.at(i).unit;
    }
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

void FacilitiesModel::insert(Facility data)
{
    this->data->insert(data, data.id);
}

void FacilitiesModel::update(Facility data)
{
    // TODO: Code update data for facilities [ priority: above normal ]
    if ( this->facility)
    this->data->update(data, data.id);
}

void FacilitiesModel::remove(QString id)
{
    // TODO: Code remove data for facilities [ priority: above normal ]
    this->data->deleteNode(data, data.id);
}

void FacilitiesModel::refresh()
{
    // TODO: Add function clear to AVL tree
    // this->data->clear();
    this->readFile();
}

AVLTree<Facility, QString>::Node *FacilitiesModel::findByDataId(QString id)
{
    AVLTree<Facility, QString>::Node *findElement = this->data->findIndex(id);
    if (findElement != nullptr)
        return findElement;
    return nullptr;
}
