#include "Facilities.h"

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
    // DArray<Facility> toDynamicArray = this->data->toDynamicArray();
    // for (int i = 0; i < toDynamicArray.getSize(); i++)
    // {
    //     qDebug() << toDynamicArray.at(i).id + ' ' + toDynamicArray.at(i).name + ' ' + toDynamicArray.at(i).unit;
    // }
    qDebug() << "Facilities Databases load:" << index;
    file.close();
}

void FacilitiesModel::show(AVLTree<Facility,QString>::Node *root, QTextStream &out)
{
    if (root != nullptr)
    {
        // xuat data nut
        out << root->data.id << ',' << root->data.name << ',' << root->data.unit << root->data.quantity;
        show(root->left, out);
        show(root->right, out);
    }
}

void FacilitiesModel::writeFile() {
    QFile file(FilePath::getPath(FilePath::databases::FACILITY));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("facility");
    }
    QTextStream out(&file);
    AVLTree<Facility, QString>::Node *currentroot = this->data->getroot();
    show(currentroot,out);
    file.close();
}

FacilitiesModel::FacilitiesModel()
{
    qDebug() << "Facility model initialized successfully";
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
    if (this->data->findIndex(data.id) == nullptr)
    {
        DataException::DataNotFound("Data with id " + data.id.toStdString() + " is not existing");
    }
    this->data->update(data, data.id);
}

void FacilitiesModel::remove(QString id)
{
    AVLTree<Facility, QString>::Node *element = this->data->findIndex(id);
    if (element == nullptr)
    {
        DataException::DataNotFound("Data with id " + id.toStdString() + " is not existing");
    }
    this->data->remove(element, element->key);
}

void FacilitiesModel::refresh()
{
    // TODO: Add function clear to AVL tree
    this->data->clear();
    this->readFile();
}

Facility *FacilitiesModel::findByDataId(QString id)
{
    Facility *findElement = &this->data->findIndex(id)->data;
    return findElement;
}
