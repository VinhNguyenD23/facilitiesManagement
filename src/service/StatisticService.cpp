#include "StatisticService.h"
#include "../model/GlobalModel.h"
#include "../exception/ValidateException.h"

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

DArray<Invoice> StatisticService::statisticTime(QDate from, QDate to)
{
    DArray<Invoice> result = DArray<Invoice>(10000);
    auto *head = this->invoiceRepository->getList();
    while(head != nullptr)
    {
        int getCurrentDay = head->data.date.day;
        int getCurrentMonth = head->data.date.month;
        int getCurrentYear = head->data.date.year;
        if ( getCurrentYear < from.year() || getCurrentYear > to.year())
        {
            head = head->next;
            if (ValidateUtil::isNull(head)) break;
            continue;
        }
        if ( getCurrentYear == from.year())
        {
            if ( getCurrentMonth < from.month() || (getCurrentMonth == from.month() && getCurrentDay < from.day()))
            {
                head = head->next;
                if (ValidateUtil::isNull(head)) break;
                continue;
            }
        }
        if (getCurrentYear == to.year())
        {
            if ( getCurrentMonth > to.month() || (getCurrentMonth == to.month() && getCurrentDay > to.day()))
            {
                head = head->next;
                if (ValidateUtil::isNull(head)) break;
                continue;
            }
        }
        result.push(head->data);
        head = head->next;
    }
    return result;
}
