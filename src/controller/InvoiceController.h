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
    void createNewInvoice(QString staffId, Invoice &data);
    void updateExistInvoice(QString staffId, Invoice &data);
    void removeInvoice(QString staffId, Invoice &data);
    LinkedList<Invoice>::Node *getListInvoices(QString staffId);
    Invoice *getInvoiceById(QString id);
    double getSumOfInvoice(QString staffId, QString id);
    ~InvoiceController();
};

#endif
