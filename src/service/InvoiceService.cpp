#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->invoiceRepository = invoiceModel;
    this->staffRepository = staffModel;
    qDebug() << "Invoice service initialized successfully";
}

void InvoiceService::create(Invoice data)
{
    this->invoiceRepository->insert(data);
}

LinkedList<Invoice> *InvoiceService::readAll()
{
    return this->invoiceRepository->getList();
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
    this->invoiceRepository->update(data);
}

void InvoiceService::remove(Invoice data)
{
    if (this->invoiceRepository->getDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    this->invoiceRepository->remove(data);
}

InvoiceService::~InvoiceService()
{
}
