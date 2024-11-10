#ifndef FACILITYSERVICE_H
#define FACILITYSERVICE_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include "../datatype/LinkedList.h"
#include "../model/GlobalModel.h"
#include <QString>

class FacilityService
{
private:
    /* data */
    FacilitiesModel *facilityRepository = nullptr;
public:
    FacilityService(/* args */);
    void create(Facility data);
    AVLTree<Facility> *readAll();
    Facility *readById(QString id);
    void update(Facility data);
    void remove(Facility data);
    ~FacilityService();
};

#endif