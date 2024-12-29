#ifndef INVOICEDETAILSERVICE_H
#define INVOICEDETAILSERVICE_H
#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "../model/Facilities.h"
#include "../model/InvoiceDetail.h"
#include "../model/Invoices.h"
#include <QString>

class InvoiceDetailService
{
private:
    InvoiceDetailModel *invoiceDetailRepository = nullptr;
    FacilitiesModel *facilityRepository = nullptr;
    InvoiceModel *invoiceRepository = nullptr;

public:
    InvoiceDetailService();
    InvoiceDetailService(QString staffId, QString invoiceId);
    void create(InvoiceDetail data);
    // void update(InvoiceDetail &data);
    // void remove(InvoiceDetail &data);
    LinkedList<InvoiceDetail>::Node *readAll();
    // InvoiceDetail *readById(QString id);
    ~InvoiceDetailService();
};

#endif
