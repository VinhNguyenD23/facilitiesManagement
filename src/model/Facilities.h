#ifndef FACILITIES_H
#define FACILITIES_H

#include <iostream>
#include "../object/facility.h"
#include "../datatype/Avl.h"

class FacilitiesModel
{
private:
    AVLTree<Facility, std::string> *data;

public:
    FacilitiesModel();
    AVLTree<Facility, std::string> *getListData();
    AVLTree<Facility, std::string> *updateData(Facility data);
    AVLTree<Facility, std::string> *removeData(std::string id);
    AVLTree<Facility, std::string>::Node *findByDataId(std::string id);
};

#endif // FACILITIES_H
