#include "Facilities.h"
#include<vector>
#include<fstream>
#include<sstream>


FacilitiesModel::FacilitiesModel()
{
    // TODO: Read data from databases [*.csv] in ../databases [ priority: high ]
    // this->data = nullptr;
    this -> data = AVLTree<Facility, std::string>;
    std::fstream f("../databases/Facilities.csv", std::ios::in | std::ios::out);
    std::string line;
    if(f.is_open())
    {
        while (getline(f, line))
        {
            std::istringstream fileData(line);
            std::string tempData;
            Facility getUser;
            AVLTree<std::string> facilities;
            Node* root = new node();
            std::string quantity_str;
            // while (getline(fileData, tempData, ','))
            // {
            //     temp.insert(tempData);
            // }
            // std::cout << std::endl;
            std::getline(fileData, getUser.id, ',');
            std::getline(fileData, getUser.name, ',');
            std::getline(fileData, getUser.unit, ',');
            std::getline(fileData, quantity_str, ',');

            // Convert quantity from string to long
            getUser.quantity = std::stol(quantity_str);

            // Insert the facility into the AVL tree
            root = facilities.insert(root, getUser);
        }

    f.close();
    return root;
    }
    else
    {
        throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
}

FacilitiesModel::~FacilitiesModel()
{
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
