#ifndef STATISTICCTRL_H
#define STATISTICCTRL_H

#include "../service/StatisticService.h"
#include "../controller/InvoiceController.h"
#include "../datatype/LinkedList.h"

class StatisticController
{
private:
    InvoiceController *invoice = nullptr;

public:
    StatisticController();
    LinkedList<Invoice> *getTopInvoices(int limit);

};

#endif
