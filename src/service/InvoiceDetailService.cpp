#include "InvoiceDetailService.h"
#include "../model/GlobalModel.h"
#include "../util/ValidateUtil.h"
#include "../exception/DataException.h"
#include "../exception/LogicException.h"

InvoiceDetailService::InvoiceDetailService()
{
    // this->invoiceDetailRepository = invoiceDetailModel;
    // this->facilityRepository = facilityModel;
    // this->invoiceRepository = invoiceModel;
}

InvoiceDetailService::InvoiceDetailService(QString staffId, QString invoiceId)
{
    this->invoiceDetailRepository = new InvoiceDetailModel(invoiceId);
    this->facilityRepository = facilityModel;
    this->invoiceRepository = new InvoiceModel(staffId);
}

void InvoiceDetailService::create(InvoiceDetail data)
{
    Facility *getFacility = this->facilityRepository->findByDataId(data.facilityId);
    bool invoiceType = this->invoiceRepository->findById(this->invoiceDetailRepository->getInvoiceId())->type;
    if (ValidateUtil::isNull(getFacility))
    {
        throw DataException::DataNotFound("Facility id not found, please try again!");
    }
    if (!invoiceType && getFacility->quantity - data.quantity < 0)
    {
        std::string message = "The updated quantity must be less than the available stock (available: " + QString::number(getFacility->quantity).toStdString() + ")" + " please try again";
        throw LogicException::NegativeValue(message);
    }
    Facility tempData = Facility(*getFacility);
    tempData.quantity = (invoiceType ? (getFacility->quantity + data.quantity) : (getFacility->quantity - data.quantity));
    this->facilityRepository->update(tempData);
    this->invoiceDetailRepository->push(data);
}

// void InvoiceDetailService::update(InvoiceDetail &data)
// {
//     auto *existingData = this->invoiceDetailRepository->findById(data.id);
//     if (ValidateUtil::isNull(existingData))
//     {
//         throw DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
//     }
//     Facility *getFacility = this->facilityRepository->findByDataId(data.facilityId);
//     bool invoiceType = this->invoiceRepository->findById(data.invoiceId)->type;
//     if (ValidateUtil::isNull(getFacility))
//     {
//         throw DataException::DataNotFound("Facility id not found, please try again!");
//     }
//     if (existingData->facilityId != getFacility->id)
//     {
//         throw DataException::CantHandle(data.id.toStdString() + " can't change facility id");
//     }
//     Facility tempData = Facility(*getFacility);
//     int changeValue = data.quantity - existingData->quantity;
//     tempData.quantity += (invoiceType ? changeValue : -changeValue);
//     this->facilityRepository->update(tempData);
//     this->invoiceDetailRepository->update(data);
// }

// void InvoiceDetailService::remove(InvoiceDetail &data)
// {
//     auto *existingData = this->invoiceDetailRepository->findById(data.id);
//     if (ValidateUtil::isNull(existingData))
//     {
//         throw DataException::DataNotFound("Not found any invoice detail with id: " + data.id.toStdString());
//     }
//     Facility *getFacility = this->facilityRepository->findByDataId(data.facilityId);
//     bool invoiceType = this->invoiceRepository->findById(data.invoiceId)->type;
//     if (ValidateUtil::isNull(getFacility))
//     {
//         throw DataException::DataNotFound("Facility id not found, please try again!");
//     }
//     Facility tempData = Facility(*getFacility);
//     tempData.quantity += (invoiceType ? -data.quantity : data.quantity);
//     this->facilityRepository->update(tempData);
//     this->invoiceDetailRepository->remove(data);
// }

LinkedList<InvoiceDetail>::Node *InvoiceDetailService::readAll()
{
    return this->invoiceDetailRepository->getList();
}

// InvoiceDetail *InvoiceDetailService::readById(QString id)
// {
//     return this->invoiceDetailRepository->findById(id);
// }

InvoiceDetailService::~InvoiceDetailService()
{
}
