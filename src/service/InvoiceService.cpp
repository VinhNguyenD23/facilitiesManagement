#include "InvoiceService.h"

InvoiceService::InvoiceService()
{
    this->invoiceRepository = invoiceModel;
    this->staffRepository = staffModel;
    this->invoiceDetailRepository = invoiceDetailModel;
    qDebug() << "Invoice service initialized successfully";
}

void InvoiceService::create(Invoice data)
{
    if (this->staffRepository->getDataById(data.staffId) == nullptr)
    {
        throw DataException::DataNotFound("Staff id not found! Please try again.");
    }
    if(data.id.length() > 20 || data.id.length() == 0)
    {
        throw ValidateException::InvalidData("Staff id length must in range [1, 20], please try again");
    }
    this->invoiceRepository->insert(data);
}

LinkedList<Invoice> *InvoiceService::readAll()
{
    return this->invoiceRepository->getList();
}

Invoice *InvoiceService::readById(QString id)
{
    Invoice *invoiceDetail = this->invoiceRepository->findDataById(id);
    if (invoiceDetail == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    return invoiceDetail;
}

void InvoiceService::update(Invoice data)
{
    if (this->invoiceRepository->findDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    this->invoiceRepository->update(data);
}

void InvoiceService::remove(Invoice data)
{
    if (this->invoiceRepository->findDataById(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + data.id.toStdString());
    }
    this->invoiceRepository->remove(data);
}

double InvoiceService::getSum(QString id)
{
    if (this->invoiceRepository->findDataById(id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any invoice with invoice id: " + id.toStdString());
    }
    double sum = 0.00;
    auto *current = this->invoiceDetailRepository->getList()->getListData();
    while (current != nullptr)
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
