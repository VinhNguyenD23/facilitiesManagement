#ifndef INVOICEDETAILMODEL_H
#define INVOICEDETAILMODEL_H

#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "data.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
class InvoiceDetailModel
{
private:
    LinkedList<InvoiceDetail> *data;
    Data *getCurrentData = nullptr;
    QString invoiceId;

private:
    void readFile();
    void writeFile();

public:
    InvoiceDetailModel();
    InvoiceDetailModel(QString invoiceId);
    LinkedList<InvoiceDetail>::Node *getList();
    void push(InvoiceDetail data);
    void remove(InvoiceDetail data);
    void update(InvoiceDetail data);
    void refresh();
    // InvoiceDetail *findById(QString id);
    bool isFacilityAvailable(QString facilityId);
    size_t getSize();
    double getSum(InvoiceDetail data);
    ~InvoiceDetailModel();
    QString getInvoiceId();
};

#endif
