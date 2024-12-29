#ifndef INVOICESERVICE_H
#define INVOICESERVICE_H
#include "../object/Invoice.h"
#include "../datatype/LinkedList.h"
#include "../model/Invoices.h"
#include "../model/Staffs.h"
#include "../model/InvoiceDetail.h"
#include <QString>

class InvoiceService
{
private:
    /* data */
    // InvoiceModel *invoiceRepository = nullptr;
    StaffsModel *staffRepository = nullptr;
    // InvoiceDetailModel *invoiceDetailRepository = nullptr;
    Data *newData;


public:
    InvoiceService(/* args */);
    void create(QString staffId, Invoice &data);
    void update(QString staffId, Invoice &data);
    void remove(QString staffId, Invoice &data);
    LinkedList<Invoice>::Node *readAll(QString staffId);
    Invoice *readById(QString id);
    double getSum(QString staffId, QString id);
    ~InvoiceService();
};

#endif
