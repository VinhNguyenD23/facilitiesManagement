#include "InvoiceDetailController.h"

InvoiceDetailController::InvoiceDetailController()
{
    this->invoiceDetailService = new InvoiceDetailService();
}

void InvoiceDetailController::createNewInvoiceDetail(InvoiceDetail data)
{
    this->invoiceDetailService->create(data);
}

void InvoiceDetailController::updateExistInvoiceDetail(InvoiceDetail data)
{
    this->invoiceDetailService->update(data);
}

void InvoiceDetailController::removeInvoiceDetail(InvoiceDetail data)
{
    this->invoiceDetailService->remove(data);
}

LinkedList<InvoiceDetail> *InvoiceDetailController::getListInvoice()
{
    return this->invoiceDetailService->readAll();
}

InvoiceDetail *InvoiceDetailController::getInvoiceDetailByDetailId(QString id)
{
    return this->invoiceDetailService->readById(id);
}

InvoiceDetailController::~InvoiceDetailController()
{
}
