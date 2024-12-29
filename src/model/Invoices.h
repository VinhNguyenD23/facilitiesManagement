#ifndef INVOICEMODEL_H
#define INVOICEMODEL_H
#include "../datatype/LinkedList.h"
#include "../object/Invoice.h"
#include "InvoiceDetail.h"
#include "data.h"
#include "Staffs.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class InvoiceModel
{
private:
    LinkedList<Invoice> *data;
    StaffsModel *staffRepository = nullptr;
    Data *getCurrentData = nullptr;
    QString staffId;

private:
    void readFile();
    void writeFile();

public:
    InvoiceModel();
    InvoiceModel(QString staffId);
    ~InvoiceModel();
    LinkedList<Invoice>::Node *getList();
    void push(Invoice data);
    void remove(Invoice data);
    void update(Invoice data);
    void refresh();
    Invoice *findById(QString id);
    size_t getSize();
    // void loadInvoiceDetailData();
    // void addInvoiceDetail(QString invoiceId, InvoiceDetail &data);
    // void refreshInvoiceDetail();
    static double getSumOfInvoice(QString id)
    {
        InvoiceDetailModel *invoiceDetailRepository = new InvoiceDetailModel(id);
        double sum = 0.00;
        if (ValidateUtil::isNull(invoiceDetailRepository->getList()))
        {
            return sum;
        }
        auto *current = invoiceDetailRepository->getList();
        while (!ValidateUtil::isNull(current))
        {
            sum += InvoiceDetailModel::getSum(current->data);
            // sum += double(current->data.price * current->data.quantity) * double(1.0 + current->data.vat);
            current = current->next;
        }
        return sum;
    }
};

#endif
