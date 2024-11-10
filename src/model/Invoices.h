#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H
#include "../datatype/LinkedList.h"
#include "../object/Date.h"
#include "../object/Invoice.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../common/FilePath.h"
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
    LinkedList<Invoice> *getListData();
    void insert(Invoice data);
    void remove(Invoice data);
    void update(Invoice data);
    void refresh();
    Invoice *getDataById(QString id);
    size_t getSize();
    ~InvoiceModel();
};

#endif
