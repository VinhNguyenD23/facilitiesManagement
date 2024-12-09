#ifndef INVOICEDETAILSERVICE_H
#define INVOICEDETAILSERVICE_H
#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "../model/GlobalModel.h"
#include "../exception/DataException.h"
#include "../exception/LogicException.h"
#include "../model/InvoiceDetail.h"
#include <QString>

class InvoiceDetailService
{
private:
    InvoiceDetailModel *invoiceDetailRepository = nullptr;
    FacilitiesModel *facilityRepository = nullptr;
    InvoiceModel *invoiceRepository = nullptr;

public:
    InvoiceDetailService(/* args */);
    void create(InvoiceDetail data);
    void update(InvoiceDetail data);
    void remove(InvoiceDetail data);
    LinkedList<InvoiceDetail> *readAll();
    InvoiceDetail *readById(QString id);
    ~InvoiceDetailService();
};

#endif
