#ifndef DATA_H
#define DATA_H
#include "../object/Staff.h"
#include "../datatype/PointerArray.h"
#include "../datatype/LinkedList.h"

class Data
{
private:
    PointerArray<Staff> *staffModel = nullptr;
    void readFile();
public:
    Data();
    void writeFile();
    Staff *findStaffById(QString id);
    LinkedList<Invoice> *findInvoiceListByStaffId(QString staffId);
    LinkedList<InvoiceDetail> *findInvoiceDetailListByInvoiceId(QString invoiceId);
    PointerArray<Staff> *getCurrent();
    void pushToInvoiceListByStaffId(QString staffId, Invoice data);
    void removeToInvoiceListByStaffId(QString staffId, Invoice data);
    void updateToInvoiceListByStaffId(QString staffId, Invoice data);
    void pushToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data);
    void removeToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data);
    void updateToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data);

};

#endif // DATA_H
