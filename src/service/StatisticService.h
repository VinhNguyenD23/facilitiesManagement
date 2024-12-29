#ifndef STATISTICSERVICE_H
#define STATISTICSERVICE_H

#include "../datatype/DynamicArray.h"
#include "../datatype/Pair.h"
#include "../object/Invoice.h"
#include "../model/Staffs.h"
#include <QString>
#include <QDate>

class StatisticService
{
private:
    LinkedList<Invoice> *getList;
    // InvoiceModel *invoiceRepository = nullptr;
    // InvoiceDetailModel *invoiceDetailRepository = nullptr;
    StaffsModel *staffRepository = nullptr;

public:
    StatisticService();
    DArray<double> statisticYear(int year);
    DArray<Staff> statisticTime(QDate from, QDate to);
    DArray<Pair<QString, double>> statisticFacilityByTime(QDate from, QDate to);
};

#endif
