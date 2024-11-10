#include "InvoiceDetailService.h"

InvoiceDetailService::InvoiceDetailService()
{
    this->invoiceDetailRepository = invoiceDetailModel;
}

void InvoiceDetailService::create(InvoiceDetail data)
{
    this->invoiceDetailRepository->insertData(data);
}

void InvoiceDetailService::update(InvoiceDetail data)
{
    if (this->invoiceDetailRepository->getDataById(data.id))
    {
        DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->updateData(data);
}

void InvoiceDetailService::remove(InvoiceDetail data)
{
    if (this->invoiceDetailRepository->getDataById(data.id))
    {
        DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->removeData(data);
}

LinkedList<InvoiceDetail> *InvoiceDetailService::readAll()
{
    return nullptr;
}

InvoiceDetail *InvoiceDetailService::readById(QString id)
{
    return nullptr;
}

InvoiceDetailService::~InvoiceDetailService()
{
}
