#include "StatisticService.h"
#include "../model/GlobalModel.h"
#include "../util/ArrayUtil.h"
#include "../model/Invoices.h"
#include "../model/InvoiceDetail.h"

StatisticService::StatisticService()
{
    // this->invoiceRepository = invoiceModel;
    // this->invoiceDetailRepository = invoiceDetailModel;
    this->staffRepository = staffModel;
}

DArray<double> StatisticService::statisticYear(int year)
{
    DArray<double> monthlyRevenue = DArray<double>(13);
    for(int staffIndex = 0; staffIndex < this->staffRepository->getSize(); staffIndex++)
    {
        auto *current = this->staffRepository->getList();
        InvoiceModel *invoiceRepository = new InvoiceModel(current->at(staffIndex)->id);
        for (int i = 1; i <= 12; i++)
        {
            double sum = 0.00;
            auto head = invoiceRepository->getList();
            while (!ValidateUtil::isNull(head))
            {
                if (head->data.date.month == i && head->data.date.year == year && head->data.type == 0)
                {
                    sum += invoiceRepository->getSumOfInvoice(head->data.id);
                }
                head = head->next;
            }
            monthlyRevenue.at(i) += sum;
            monthlyRevenue.at(0) += sum;
            qDebug() << i << ':' << monthlyRevenue.at(i);
        }
    }

    return monthlyRevenue;
}

DArray<Staff> StatisticService::statisticTime(QDate from, QDate to)
{
    DArray<Staff> result = DArray<Staff>(10000);
    for(int staffIndex = 0; staffIndex < this->staffRepository->getSize(); staffIndex++)
    {
        Staff staffData = Staff(*this->staffRepository->getList()->at(staffIndex));
        auto *invoiceRepository = new InvoiceModel(this->staffRepository->getList()->at(staffIndex)->id);
        auto *head = invoiceRepository->getList();
        staffData.invoicesList = new LinkedList<Invoice>();
        while (!ValidateUtil::isNull(head))
        {
            int getCurrentDay = head->data.date.day;
            int getCurrentMonth = head->data.date.month;
            int getCurrentYear = head->data.date.year;
            if (getCurrentYear < from.year() || getCurrentYear > to.year())
            {
                head = head->next;
                if (ValidateUtil::isNull(head))
                    break;
                continue;
            }
            if (getCurrentYear == from.year())
            {
                if (getCurrentMonth < from.month() || (getCurrentMonth == from.month() && getCurrentDay < from.day()))
                {
                    head = head->next;
                    if (ValidateUtil::isNull(head))
                        break;
                    continue;
                }
            }
            if (getCurrentYear == to.year())
            {
                if (getCurrentMonth > to.month() || (getCurrentMonth == to.month() && getCurrentDay > to.day()))
                {
                    head = head->next;
                    if (ValidateUtil::isNull(head))
                        break;
                    continue;
                }
            }
            staffData.invoicesList->add(head->data);
            head = head->next;
        }
        if(!ValidateUtil::isNull(staffData.invoicesList->getList()))
            result.push(staffData);
    }

    return result;
}

DArray<Pair<QString, double>> StatisticService::statisticFacilityByTime(QDate from, QDate to)
{
    DArray<Pair<QString, double>> result = DArray<Pair<QString, double>>();
    for(int staffIndex = 0; staffIndex < this->staffRepository->getSize(); staffIndex++)
    {
        auto *invoiceRepository = new InvoiceModel(this->staffRepository->getList()->at(staffIndex)->id);
        auto *head = invoiceRepository->getList();
        int test = 0;
        while (!ValidateUtil::isNull(head))
        {
            if(head->data.type != 0)
            {
                head = head->next;
                continue;
            }
            int getCurrentDay = head->data.date.day;
            int getCurrentMonth = head->data.date.month;
            int getCurrentYear = head->data.date.year;
            if (getCurrentYear < from.year() || getCurrentYear > to.year())
            {
                head = head->next;
                if (ValidateUtil::isNull(head))
                    break;
                continue;
            }
            if (getCurrentYear == from.year())
            {
                if (getCurrentMonth < from.month() || (getCurrentMonth == from.month() && getCurrentDay < from.day()))
                {
                    head = head->next;
                    if (ValidateUtil::isNull(head))
                        break;
                    continue;
                }
            }
            if (getCurrentYear == to.year())
            {
                if (getCurrentMonth > to.month() || (getCurrentMonth == to.month() && getCurrentDay > to.day()))
                {
                    head = head->next;
                    if (ValidateUtil::isNull(head))
                        break;
                    continue;
                }
            }
            auto *invoiceDetailHead = head->data.invoiceDetailList;
            auto *invoiceDetailRepository = new InvoiceDetailModel(head->data.id);
            if (ValidateUtil::isNull(invoiceDetailHead))
            {
                head = head->next;
                continue;
            }
            auto *getInvoiceDetail = invoiceDetailHead->getList();
            while (!ValidateUtil::isNull(getInvoiceDetail))
            {
                bool isExisting = false;
                for (int index = 0; index < result.getSize(); index++)
                {
                    if (result.at(index).getFirst() == getInvoiceDetail->data.facilityId)
                    {
                        isExisting = true;
                        result.at(index).setSecond(result.at(index).getSecond() + invoiceDetailRepository->getSum(getInvoiceDetail->data));
                        break;
                    }
                }
                if (isExisting == false)
                {
                    Pair<QString, double> newElement = Pair<QString, double>(getInvoiceDetail->data.facilityId, invoiceDetailRepository->getSum(getInvoiceDetail->data));
                    result.push(newElement);
                }
                getInvoiceDetail = getInvoiceDetail->next;
            }
            head = head->next;
        }
        if (result.getSize() > 0)
        {
            for (int firstElement = 0; firstElement < result.getSize() - 1; firstElement++)
            {
                int maxIndex = firstElement;
                for (int secondElement = firstElement + 1; secondElement < result.getSize(); secondElement++)
                {
                    if (result.at(secondElement).getSecond() > result.at(maxIndex).getSecond())
                    {
                        maxIndex = secondElement;
                    }
                }
                ArrayUtil<Pair<QString, double>>::swap(result.at(firstElement), result.at(maxIndex));
            }
        }
    }

    return result;
}
