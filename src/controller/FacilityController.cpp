#include "FacilityController.h"

FacilityController::FacilityController()
{
    this->facilityService = new InvoiceService();
}

void FacilityController::createNewFacility(Facility data) {
    this->facilityService->create(data);
}

void FacilityController::updateExistFacility(Facility data) {
    this->facilityService->update(data);
}

void FacilityController::removeFacility(Facility data) {
    this->facilityService->remove(data);
}

Avltree<Facility> *FacilityController::getListFacilities() {
    
    return nullptr;
}


FacilityController::~FacilityController()
{
}
