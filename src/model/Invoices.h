#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H
#include "../datatype/LinkedList.h"
#include "../object/Invoice.h"
#include <QFile>
#include <QTextStream>
class InvoiceModel
{
private:
    linkedList<Invoice> *data;

public:
    InvoiceModel();
    linkedList<Invoice> *getListData();
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
