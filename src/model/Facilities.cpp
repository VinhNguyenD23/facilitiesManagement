#include "Facilities.h"

FacilitiesModel::FacilitiesModel()
{ // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]
    this->data = new AVLTree<Facility, QString>();
    QFile file(FilePath::getPath(FilePath::databases::FACILITY));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("[ERROR] This database (facilities) not found or broken, please try again !");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw std::runtime_error("[ERROR] This database (facilities) not found or broken, please try again !");
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
}

FacilitiesModel::~FacilitiesModel()
{
}

AVLTree<Facility, QString> *FacilitiesModel::getListData()
{
    return this->data;
}

void FacilitiesModel::updateData(Facility data)
{
    // TODO: Code update data for facilities [ priority: above normal ]
    this->data->insert(data, data.id);
}

void FacilitiesModel::removeData(QString id)
{
    // TODO: Code remove data for facilities [ priority: above normal ]
}

AVLTree<Facility, QString>::Node *FacilitiesModel::findByDataId(QString id)
{
    AVLTree<Facility, QString>::Node *findElement = this->data->findIndex(id);
    if (findElement != nullptr)
        return findElement;
    return nullptr;
}
