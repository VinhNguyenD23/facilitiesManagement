#ifndef STATISTICSERVICE_H
#define STATISTICSERVICE_H

#include "../datatype/DynamicArray.h"
#include "../datatype/Pair.h"
#include "../object/Invoice.h"
#include "../model/Invoices.h"
#include "../model/InvoiceDetail.h"
#include <QString>
#include <QDate>

class StatisticService
{
private:
    LinkedList<Invoice> *getList;
    InvoiceModel *invoiceRepository = nullptr;
    InvoiceDetailModel *invoiceDetailRepository = nullptr;

public:
    StatisticService();
    DArray<double> statisticYear(int year);
    DArray<Invoice> statisticTime(QDate from, QDate to);
    DArray<Pair<QString, double>> statisticFacilityByTime(QDate from, QDate to);
};

#endif
