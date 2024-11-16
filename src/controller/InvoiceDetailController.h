#ifndef INVOICEDETAILCTRL_H
#define INVOICEDETAILCTRL_H
#include "../service/InvoiceDetailService.h"
#include "../object/InvoiceDetail.h"
#include "../datatype/LinkedList.h"
#include <QString>
#include <QDebug>

class InvoiceDetailController
{
private:
    /* data */
    InvoiceDetailService *invoiceDetailService = nullptr;

public:
    InvoiceDetailController(/* args */);
    void createNewInvoiceDetail(InvoiceDetail data);
    void updateExistInvoiceDetail(InvoiceDetail data);
    void removeInvoiceDetail(InvoiceDetail data);
    LinkedList<InvoiceDetail> *getListInvoice();
    InvoiceDetail *getInvoiceDetailByDetailId(QString id);
    ~InvoiceDetailController();
};

#endif
