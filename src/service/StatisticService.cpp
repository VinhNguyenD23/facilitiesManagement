#include "StatisticService.h"

StatisticService::StatisticService()
{
    this->invoiceRepository = invoiceModel;
}

DArray<double> StatisticService::statisticYear(int year)
{
    DArray<double> monthlyRevenue = DArray<double>(13);
    for (int i = 1; i <= 12; i++)
    {
        double sum = 0;
        auto head = this->invoiceRepository->getList();
        while (!ValidateUtil::isNull(head))
        {
            if (head->data.date.month == i && head->data.date.year == year && head->data.type == 0)
            {
                sum += this->invoiceRepository->getSumOfInvoice(head->data.id);
            }
            head = head->next;
        }
        monthlyRevenue.at(i) = sum;
        monthlyRevenue.at(0) += sum;
    }
    return monthlyRevenue;
}
