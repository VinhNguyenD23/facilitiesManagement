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
    LinkedList<Invoice> *getList();
    void insert(Invoice data);
    void remove(Invoice data);
    void update(Invoice data);
    void refresh();
    Invoice *findDataById(QString id);
    bool isStaffAvailable(QString staffId);
    size_t getSize();
    ~InvoiceModel();
};

#endif
