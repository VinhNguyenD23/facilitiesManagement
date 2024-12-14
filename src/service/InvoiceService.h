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
    InvoiceModel *invoiceRepository = nullptr;
    StaffsModel *staffRepository = nullptr;
    InvoiceDetailModel *invoiceDetailRepository = nullptr;


public:
    InvoiceService(/* args */);
    void create(Invoice data);
    LinkedList<Invoice> *readAll();
    Invoice *readById(QString id);
    void update(Invoice data);
    void remove(Invoice data);
    double getSum(QString id);
    ~InvoiceService();
};

#endif
