#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->invoiceRepository = invoiceModel;
    this->staffRepository = staffModel;
}

void InvoiceService::create(Invoice data)
{
    this->invoiceRepository->insertData(data);
}

LinkedList<Invoice> *InvoiceService::readAll()
{
    return this->invoiceRepository->getListData();
}

Invoice *InvoiceService::readById(QString id)
{
    Invoice *invoiceDetail = this->invoiceRepository->getDataById(id);
    if (invoiceDetail == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    return invoiceDetail;
}

void InvoiceService::update(Invoice data)
{
    if (this->invoiceRepository->getDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    this->invoiceRepository->updateData(data);
}

void InvoiceService::remove(Invoice data)
{
    if (this->invoiceRepository->getDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    this->invoiceRepository->removeData(data);
}

InvoiceService::~InvoiceService()
{
}
