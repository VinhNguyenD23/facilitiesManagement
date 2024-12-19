#ifndef INVOICECTRL_H
#define INVOICECTRL_H
#include "../service/InvoiceService.h"
#include "../datatype/LinkedList.h"
#include "../object/Invoice.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

class InvoiceController
{
private:
    InvoiceService *invoiceService = nullptr;

public:
    InvoiceController(/* args */);
    void createNewInvoice(Invoice &data);
    void updateExistInvoice(Invoice &data);
    void removeInvoice(Invoice &data);
    LinkedList<Invoice>::Node *getListInvoices();
    Invoice *getInvoiceById(QString id);
    double getSumOfInvoice(QString id);
    ~InvoiceController();
};

#endif
