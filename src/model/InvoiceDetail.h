#ifndef INVOICEDETAILMODEL_H
#define INVOICEDETAILMODEL_H

#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include "../exception/DatabasesException.h"
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

public:
    InvoiceDetailModel();
    LinkedList<InvoiceDetail> *getListData();
    void insertData(InvoiceDetail data);
    void removeData(InvoiceDetail data);
    void updateData(InvoiceDetail data);
    void refreshData();
    InvoiceDetail *getDataById(QString id);
    size_t getSize();
    ~InvoiceDetailModel();
};

#endif
