#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H
#include "../datatype/LinkedList.h"
#include "../object/Date.h"
#include "../object/Invoice.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class InvoiceModel
{
private:
    LinkedList<Invoice> *data;

private:
    void readFile();
    void writeFile();

public:
    InvoiceModel();
    ~InvoiceModel();
    LinkedList<Invoice>::Node *getList();
    void push(Invoice &data);
    void remove(Invoice &data);
    void update(Invoice &data);
    void refresh();
    Invoice *findById(QString id);
    bool isStaffAvailable(QString staffId);
    size_t getSize();
    void loadInvoiceDetailData();
    void addInvoiceDetail(QString invoiceId, InvoiceDetail &data);
    void refreshInvoiceDetail();

};

#endif
