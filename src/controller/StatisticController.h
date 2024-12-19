#ifndef STATISTICCTRL_H
#define STATISTICCTRL_H

#include "../service/StatisticService.h"
#include "../datatype/DynamicArray.h"

class StatisticController
{
private:
    StatisticService *statisticService = nullptr;

public:
    StatisticController();
    DArray<double> getStatisticInvoiceOfYear(int year);

};

#endif
