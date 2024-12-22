#ifndef INVOICEDETAILMODEL_H
#define INVOICEDETAILMODEL_H

#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "Invoices.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
class InvoiceDetailModel
{
private:
    LinkedList<InvoiceDetail> *data;
    InvoiceModel *invoiceRepository = nullptr;

private:
    void readFile();
    void writeFile();

public:
    InvoiceDetailModel();
    LinkedList<InvoiceDetail>::Node *getList();
    void push(InvoiceDetail &data);
    void remove(InvoiceDetail &data);
    void update(InvoiceDetail &data);
    void refresh();
    InvoiceDetail *findById(QString id);
    bool isFacilityAvailable(QString facilityId);
    size_t getSize();
    double getSum(InvoiceDetail &data);
    ~InvoiceDetailModel();
};

#endif
