#ifndef FACILITYSERVICE_H
#define FACILITYSERVICE_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include "../datatype/LinkedList.h"
#include "../model/GlobalModel.h"
#include "../model/Facilities.h"
#include "../exception/ValidateException.h"
#include <QString>

class FacilityService
{
private:
    /* data */
    FacilitiesModel *facilityRepository = nullptr;
    InvoiceDetailModel *invoiceDetailRepository = nullptr;

public:
    FacilityService(/* args */);
    void create(Facility data);
    AVLTree<Facility, QString> *readAll();
    Facility *readById(QString id);
    void update(Facility data);
    void remove(Facility data);
    ~FacilityService();
};

#endif
