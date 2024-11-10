#ifndef FACILITYCTRL_H
#define FACILITYCTRL_H
#include "../service/FacilityService.h"
#include "../object/Invoice.h"
#include "../datatype/Avl.h"
class FacilityController
{
private:
    /* data */
    FacilityController *facilityService = nullptr;
public:
    FacilityController();
    void createNewFacility(Facility data);
    void updateExistFacility(Facility data);
    void removeFacility(Facility data);
    AVLTree<Facility> *getListFacilities();
    ~FacilityController();
};

#endif
