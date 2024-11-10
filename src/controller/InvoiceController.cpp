#include "InvoiceController.h"

InvoiceController::InvoiceController()
{
    this->invoiceService = new InvoiceService();
}

void InvoiceController::createNewInvoice(Invoice data)
{
    this->invoiceService->create(data);
}

void InvoiceController::updateExistInvoice(Invoice data)
{
    this->invoiceService->update(data);
}

void InvoiceController::removeInvoice(Invoice data)
{
    this->invoiceService->remove(data);
}

LinkedList<Invoice> *InvoiceController::getListInvoices()
{
    return nullptr;
}

Invoice *InvoiceController::getInvoiceById(QString id)
{
    return nullptr;
}

InvoiceController::~InvoiceController()
{
}
