#ifndef FACILITYCTRL_H
#define FACILITYCTRL_H
#include "../service/FacilityService.h"
#include "../object/Invoice.h"
#include "../datatype/Avl.h"
#include <QMessageBox>
#include <QDebug>
class FacilityController
{
private:
    /* data */
    FacilityService *facilityService = nullptr;

public:
    FacilityController();
    void createNewFacility(Facility data);
    void updateExistFacility(Facility data);
    void removeFacility(Facility data);
    AVLTree<Facility, QString> *getListFacilities();
    ~FacilityController();
};

#endif
