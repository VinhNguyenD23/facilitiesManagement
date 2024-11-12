#ifndef INVOICECTRL_H
#define INVOICECTRL_H
#include "../service/InvoiceService.h"
#include "../object/Invoice.h"
#include <QString>
#include <QMessageBox>
#include "../datatype/LinkedList.h"
class InvoiceController
{
private:
    InvoiceService *invoiceService = nullptr;

public:
    InvoiceController(/* args */);
    void createNewInvoice(Invoice data);
    void updateExistInvoice(Invoice data);
    void removeInvoice(Invoice data);
    LinkedList<Invoice> *getListInvoices();
    Invoice *getInvoiceById(QString id);
    ~InvoiceController();
};

#endif