#include "InvoiceDetailService.h"

InvoiceDetailService::InvoiceDetailService()
{
    this->invoiceDetailRepository = invoiceDetailModel;
    qDebug() << "Invoice detail service initialized successfully";
}

void InvoiceDetailService::create(InvoiceDetail data)
{
    if (this->invoiceDetailRepository->getDataById(data.id))
    {
        throw DataException::DuplicateDataId("This id is existing, please try again!");
    }
    this->invoiceDetailRepository->insert(data);
}

void InvoiceDetailService::update(InvoiceDetail data)
{
    if (this->invoiceDetailRepository->getDataById(data.id))
    {
        DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->update(data);
}

void InvoiceDetailService::remove(InvoiceDetail data)
{
    if (this->invoiceDetailRepository->getDataById(data.id))
    {
        DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->remove(data);
}

LinkedList<InvoiceDetail> *InvoiceDetailService::readAll()
{
    return this->invoiceDetailRepository->getList();
}

InvoiceDetail *InvoiceDetailService::readById(QString id)
{
    return this->invoiceDetailRepository->getDataById(id);
}

InvoiceDetailService::~InvoiceDetailService()
{
}
