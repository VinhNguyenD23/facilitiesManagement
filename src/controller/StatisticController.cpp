#include "StatisticController.h"

StatisticController::StatisticController()
{
    this->statisticService = new StatisticService();
}

DArray<double> StatisticController::getStatisticInvoiceOfYear(int year)
{
    return this->statisticService->statisticYear(year);
}
