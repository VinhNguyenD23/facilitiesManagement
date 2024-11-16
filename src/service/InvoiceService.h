#ifndef INVOICESERVICE_H
#define INVOICESERVICE_H
#include "../object/Invoice.h"
#include "../datatype/LinkedList.h"
#include "../model/GlobalModel.h"
#include "../exception/DataException.h"
#include <QString>
#include "../model/Invoices.h"
#include "../model/Staffs.h"

class InvoiceService
{
private:
    /* data */
    InvoiceModel *invoiceRepository = nullptr;
    StaffsModel *staffRepository = nullptr;

public:
    InvoiceService(/* args */);
    void create(Invoice data);
    LinkedList<Invoice> *readAll();
    Invoice *readById(QString id);
    void update(Invoice data);
    void remove(Invoice data);
    ~InvoiceService();
};

#endif
