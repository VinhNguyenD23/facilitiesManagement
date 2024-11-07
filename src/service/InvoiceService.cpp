#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->invoiceRepository = invoiceModel;
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
    return this->invoiceRepository->getDataById(id);
}

void InvoiceService::update(Invoice data)
{
    if (this->invoiceRepository->getDataById(data.id))
    {
        throw std::runtime_error("[ERROR] Data not found!");
    }
}

void InvoiceService::remove(Invoice data)
{
}

InvoiceService::~InvoiceService()
{
}
