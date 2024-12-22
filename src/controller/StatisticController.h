#ifndef STATISTICCTRL_H
#define STATISTICCTRL_H

#include "../service/StatisticService.h"
#include "../datatype/DynamicArray.h"
#include "../object/Invoice.h"
#include "../datatype/Pair.h"
#include <QDate>

class StatisticController
{
private:
    StatisticService *statisticService = nullptr;

public:
    StatisticController();
    DArray<double> getStatisticInvoiceOfYear(int year);
    DArray<Invoice> getStatisticInvoiceByTime(QDate from, QDate to);
    DArray<Pair<QString, double>> getStatisticFacilityByTime(QDate from, QDate to);
};

#endif
