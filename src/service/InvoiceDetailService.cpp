#include "InvoiceDetailService.h"
#include "../model/GlobalModel.h"
#include "../exception/DataException.h"
#include "../exception/LogicException.h"

InvoiceDetailService::InvoiceDetailService()
{
    this->invoiceDetailRepository = invoiceDetailModel;
    this->facilityRepository = facilityModel;
    this->invoiceRepository = invoiceModel;
    qDebug() << "Invoice detail service initialized successfully";
}

void InvoiceDetailService::create(InvoiceDetail data)
{
    Facility *getFacility = this->facilityRepository->findByDataId(data.facilityId);
    bool invoiceType = this->invoiceRepository->findDataById(data.invoiceId)->type;
    if (this->invoiceDetailRepository->findDataById(data.id))
    {
        throw DataException::DuplicateDataId("This id is existing, please try again!");
    }
    if (getFacility == nullptr)
    {
        throw DataException::DataNotFound("Facility id not found, please try again!");
    }
    if (!invoiceType && getFacility->quantity - data.quantity < 0)
    {
        throw LogicException::NegativeValue("The updated quantity must be less than the available stock, please try again");
    }
    Facility tempData;
    tempData.id = getFacility->id;
    tempData.name = getFacility->name;
    tempData.quantity = (invoiceType ? (getFacility->quantity + data.quantity) : (getFacility->quantity - data.quantity));
    tempData.unit = getFacility->unit;
    this->facilityRepository->update(tempData);
    this->invoiceDetailRepository->insert(data);
}

void InvoiceDetailService::update(InvoiceDetail data)
{
    if (!this->invoiceDetailRepository->findDataById(data.id))
    {
        throw DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->update(data);
}

void InvoiceDetailService::remove(InvoiceDetail data)
{
    if (!this->invoiceDetailRepository->findDataById(data.id))
    {
        throw DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
    }
    this->invoiceDetailRepository->remove(data);
}

LinkedList<InvoiceDetail> *InvoiceDetailService::readAll()
{
    return this->invoiceDetailRepository->getList();
}

InvoiceDetail *InvoiceDetailService::readById(QString id)
{
    return this->invoiceDetailRepository->findDataById(id);
}

InvoiceDetailService::~InvoiceDetailService()
{
}
