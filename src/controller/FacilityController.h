#ifndef FACILITYCTRL_H
#define FACILITYCTRL_H
#include "../service/FacilityService.h"
#include "../datatype/Avl.h"
#include <QMessageBox>
#include <QString>
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
    Facility *getFacilityById(QString id);
    AVLTree<Facility, QString> *getListFacilities();
    ~FacilityController();
};

#endif
