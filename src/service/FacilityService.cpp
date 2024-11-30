#include "FacilityService.h"

FacilityService::FacilityService()
{
    this->facilityRepository = facilityModel;
    qDebug() << "Facility service initialized successfully";
}

void FacilityService::create(Facility data)
{
    if(this->facilityRepository->findByDataId(data.id) != nullptr)
    {
        throw DataException::DuplicateDataId("This data id is already exist, please try again");
    }
    if(data.id.length() > 10 || data.id.length() == 0)
    {
        throw ValidateException::InvalidData("Facility id length must in range [1, 10], please try again");
    }
    this->facilityRepository->insert(data);
}

AVLTree<Facility, QString> *FacilityService::readAll()
{
    return this->facilityRepository->getList();
}

Facility *FacilityService::readById(QString id)
{
    Facility *facilityDetail = this->facilityRepository->findByDataId(id);
    if (facilityDetail == nullptr)
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + id.toStdString());
    }
    return facilityDetail;
}

void FacilityService::update(Facility data)
{
    if (this->facilityRepository->findByDataId(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + data.id.toStdString());
    }
    this->facilityRepository->update(data);
}

void FacilityService::remove(Facility data)
{
    if (this->facilityRepository->findByDataId(data.id) == nullptr)
    {
        throw DataException::DataNotFound("Not found any facility with facility id: " + data.id.toStdString());
    }
    this->facilityRepository->remove(data.id);
}

FacilityService::~FacilityService()
{
}
