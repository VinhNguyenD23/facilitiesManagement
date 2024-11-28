#ifndef INVOICEDETAILMODEL_H
#define INVOICEDETAILMODEL_H

#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../common/FilePath.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
class InvoiceDetailModel
{
private:
    LinkedList<InvoiceDetail> *data;

private:
    void readFile();
    void writeFile();
    //TODO: writeFile()

public:
    InvoiceDetailModel();
    LinkedList<InvoiceDetail> *getList();
    void insert(InvoiceDetail data);
    void remove(InvoiceDetail data);
    void update(InvoiceDetail data);
    void refresh();
    InvoiceDetail *getDataById(QString id);
    size_t getSize();
    ~InvoiceDetailModel();
};

#endif
