#include "../exception/DataException.h"
#include "../exception/ValidateException.h"
#include "../model/GlobalModel.h"
#include "../util/ValidateUtil.h"
#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->newData = dataModel;
    this->staffRepository = staffModel;
}

void InvoiceService::create(QString staffId, Invoice &data)
{
    auto *invoiceRepository = new InvoiceModel(staffId);
    if (data.id.length() > 20 || data.id.length() == 0)
    {
        throw ValidateException::InvalidData("Id length must in range [1, 20], please try again");
    }
    if(ValidateUtil::isNull(staffRepository->findById(staffId)))
    {
        throw DataException::DataNotFound("Staff not found");
    }
    invoiceRepository->push(data);
}

LinkedList<Invoice>::Node *InvoiceService::readAll(QString staffId)
{
    auto *invoiceRepository = new InvoiceModel(staffId);
    return invoiceRepository->getList();
}

Invoice *InvoiceService::readById(QString id)
{
    Invoice *invoiceData = nullptr;
    for(int i = 0; i < this->staffRepository->getSize(); i++)
    {
        auto *invoiceRepository = new InvoiceModel(this->staffRepository->getList()->at(i)->id);
        invoiceData = invoiceRepository->findById(id);
        if(!ValidateUtil::isNull(invoiceData))break;

    }
    if (ValidateUtil::isNull(invoiceData))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    return invoiceData;
}

void InvoiceService::update(QString staffId, Invoice &data)
{
    auto *invoiceRepository = new InvoiceModel(staffId);
    if (ValidateUtil::isNull(invoiceRepository->findById(data.id)))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    if (invoiceRepository->findById(data.id)->type != data.type)
    {
        throw DataException::CantHandle(data.id.toStdString() + " can't be edited!");
    }
    invoiceRepository->update(data);
}

void InvoiceService::remove(QString staffId, Invoice &data)
{
    auto *invoiceRepository = new InvoiceModel(staffId);
    if (ValidateUtil::isNull(invoiceRepository->findById(data.id)))
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    if (!ValidateUtil::isNull(invoiceRepository->findById(data.id)->invoiceDetailList) && !ValidateUtil::isNull(invoiceRepository->findById(data.id)->invoiceDetailList->getList()))
    {
        throw DataException::CantHandle(data.id.toStdString() + " can't be removed because this invoice contains internal information!");
    }
    invoiceRepository->remove(data);
}

double InvoiceService::getSum(QString staffId, QString id)
{
    auto *invoiceRepository = new InvoiceModel(staffId);
    return invoiceRepository->getSumOfInvoice(id);
}

InvoiceService::~InvoiceService()
{
}
