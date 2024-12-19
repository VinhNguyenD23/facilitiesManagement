#ifndef STATISTICSERVICE_H
#define STATISTICSERVICE_H

#include "../object/Invoice.h"
#include "../datatype/DynamicArray.h"
#include "../model/GlobalModel.h"
#include <QString>
#include "../model/Staffs.h"
#include "../model/Invoices.h"
#include "../exception/DataException.h"
#include "../exception/ValidateException.h"

class StatisticService
{
private:
    LinkedList<Invoice> *getList;
    InvoiceModel *invoiceRepository = nullptr;

public:
    StatisticService();
    DArray<double> statisticYear(int year);
};

#endif
