#include "FacilityController.h"

FacilityController::FacilityController()
{
    try
    {
        this->facilityService = new FacilityService();
        qDebug() << "Facility controller initialized successfully";
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
}

void FacilityController::createNewFacility(Facility data)
{
    try
    {
        this->facilityService->create(data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
}

void FacilityController::updateExistFacility(Facility data)
{
    try
    {
        this->facilityService->update(data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
}

void FacilityController::removeFacility(Facility data)
{
    try
    {
        this->facilityService->remove(data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
}

AVLTree<Facility, QString> *FacilityController::getListFacilities()
{

    try
    {
        return this->facilityService->readAll();
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return nullptr;
    }
}

FacilityController::~FacilityController()
{
}
