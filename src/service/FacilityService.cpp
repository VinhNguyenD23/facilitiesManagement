#include "../model/GlobalModel.h"
#include "FacilityService.h"
#include "../exception/ValidateException.h"

FacilityService::FacilityService()
{
    this->facilityRepository = facilityModel;
    this->staffRepository = staffModel;
}

void FacilityService::create(Facility data)
{
    if (!ValidateUtil::isNull(this->facilityRepository->findByDataId(data.id)))
    {
        throw DataException::DuplicateDataId("This data id is already exist, please try again");
    }
    if (data.id.length() > 10 || data.id.length() == 0)
    {
        throw ValidateException::InvalidData("Facility id length must in range [1, 10], please try again");
    }
    this->facilityRepository->push(data);
}

AVLTree<Facility, QString> *FacilityService::readAll()
{
    return this->facilityRepository->getList();
}

Facility *FacilityService::readById(QString id)
{
    Facility *facilityDetail = this->facilityRepository->findByDataId(id);
    if (ValidateUtil::isNull(facilityDetail))
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + id.toStdString());
    }
    return facilityDetail;
}

void FacilityService::update(Facility data)
{
    if (ValidateUtil::isNull(this->facilityRepository->findByDataId(data.id)))
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + data.id.toStdString());
    }
    this->facilityRepository->update(data);
}

void FacilityService::remove(Facility data)
{
    if (ValidateUtil::isNull(this->facilityRepository->findByDataId(data.id)))
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + data.id.toStdString());
    }
    for(int staffIndex = 0; staffIndex < this->staffRepository->getSize(); staffIndex++)
    {
        auto *getCurrentInvoices = this->staffRepository->getList()->at(staffIndex)->invoicesList;
        if(ValidateUtil::isNull(getCurrentInvoices))
        {
            continue;
        }
        auto *getCurrentNodeInvoices = getCurrentInvoices->getList();
        while(!ValidateUtil::isNull(getCurrentNodeInvoices))
        {
            auto *getCurrentInvoiceDetails = getCurrentNodeInvoices->data.invoiceDetailList;
            if(ValidateUtil::isNull(getCurrentInvoiceDetails))
            {
                getCurrentNodeInvoices = getCurrentNodeInvoices->next;
                continue;
            }
            auto *getCurrentInvoiceDetailList = getCurrentInvoiceDetails->getList();
            while(!ValidateUtil::isNull(getCurrentInvoiceDetailList))
            {
                if(getCurrentInvoiceDetailList->data.facilityId == data.id)
                {
                    throw DataException::ExistDataId("Facility id is already in the invoice, cannot delete this facility");
                }
                getCurrentInvoiceDetailList = getCurrentInvoiceDetailList->next;
            }
            getCurrentNodeInvoices = getCurrentNodeInvoices->next;
        }
    }
    this->facilityRepository->remove(data.id);
}

FacilityService::~FacilityService()
{
}
