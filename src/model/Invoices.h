#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H
#include "../datatype/LinkedList.h"
#include "../object/Invoice.h"
#include "../object/Date.h"
#include "../common/FilePath.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class InvoiceModel
{
private:
    LinkedList<Invoice> *data;

public:
    InvoiceModel();
    LinkedList<Invoice> *getListData();
    void insertData(Invoice data);
    void removeData(Invoice data);
    void updateData(Invoice data);
    void refreshData();
    Invoice *getDataById(QString id);
    size_t getSize();
    template <typename T>
    void linkData(T *data);
    ~InvoiceModel();
};

#endif
