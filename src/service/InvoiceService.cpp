#include "../exception/DataException.h"
#include "../exception/ValidateException.h"
#include "../model/GlobalModel.h"
#include "../util/ValidateUtil.h"
#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->invoiceRepository = invoiceModel;
    this->staffRepository = staffModel;
    this->invoiceDetailRepository = invoiceDetailModel;
}

void InvoiceService::create(Invoice &data)
{
    if (ValidateUtil::isNull(this->staffRepository->findById(data.staffId)))
    {
        throw DataException::DataNotFound("Staff id not found! Please try again.");
    }
    if (data.id.length() > 20 || data.id.length() == 0)
    {
        throw ValidateException::InvalidData("Staff id length must in range [1, 20], please try again");
    }
    this->invoiceRepository->push(data);
}

LinkedList<Invoice>::Node *InvoiceService::readAll()
{
    return this->invoiceRepository->getList();
}

Invoice *InvoiceService::readById(QString id)
{
    Invoice *invoiceData = this->invoiceRepository->findById(id);
    if (ValidateUtil::isNull(invoiceData))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    return invoiceData;
}

void InvoiceService::update(Invoice &data)
{
    if (ValidateUtil::isNull(this->invoiceRepository->findById(data.id)))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    if (this->invoiceRepository->findById(data.id)->type != data.type)
    {
        throw DataException::CantHandle(data.id.toStdString() + " can't be edited!");
    }
    this->invoiceRepository->update(data);
}

void InvoiceService::remove(Invoice &data)
{
    if (ValidateUtil::isNull(this->invoiceRepository->findById(data.id)))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    // bool isDetailListNull = ;
    if(!ValidateUtil::isNull(this->invoiceRepository->findById(data.id)->invoiceDetailList)
        && !ValidateUtil::isNull(this->invoiceRepository->findById(data.id)->invoiceDetailList->getList()))
    {
        throw DataException::CantHandle(data.id.toStdString() + " can't be removed because this invoice contains internal information!");

    }
    this->invoiceRepository->remove(data);
}

double InvoiceService::getSum(QString id)
{
    if (ValidateUtil::isNull(this->invoiceRepository->findById(id)))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    double sum = 0.00;
    auto getInvoiceDetail = this->invoiceRepository->findById(id)->invoiceDetailList;
    if (ValidateUtil::isNull(getInvoiceDetail))
    {
        return 0;
    }
    auto *current = getInvoiceDetail->getList();
    while (!ValidateUtil::isNull(current))
    {
        if (current->data.invoiceId == id)
        {
            sum += double(current->data.price) + double(current->data.price) * current->data.vat;
        }
        current = current->next;
    }
    return sum;
}

InvoiceService::~InvoiceService()
{
}
