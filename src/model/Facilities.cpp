#include "Facilities.h"

FacilitiesModel::FacilitiesModel()
{
    // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]
    this->data = nullptr;
}

AVLTree<Facility, std::string> *FacilitiesModel::getListData()
{
    return this->data;
}

AVLTree<Facility, std::string> *FacilitiesModel::updateData(Facility data)
{
    // TODO: Code update data for facilities [ priority: above normal ]
    return nullptr;
}

AVLTree<Facility, std::string> *FacilitiesModel::removeData(std::string id)
{
    // TODO: Code remove data for facilities [ priority: above normal ]
    return nullptr;
}

AVLTree<Facility, std::string>::Node *FacilitiesModel::findByDataId(std::string id)
{
    AVLTree<Facility, std::string>::Node *findElement = this->data->findIndex(id);
    if (findElement != nullptr)
        return findElement;
    return nullptr;
}
