#include "InvoiceDetailController.h"

InvoiceDetailController::InvoiceDetailController()
{
    try
    {
        this->invoiceDetailService = new InvoiceDetailService();
        qDebug() << "Invoice detail controller initialized successfully";
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

void InvoiceDetailController::createNewInvoiceDetail(InvoiceDetail data)
{
    try
    {
        this->invoiceDetailService->create(data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
    catch(...)
    {
        qDebug() << "Unknown exception";
        QMessageBox msgBox;
        msgBox.setText("Something is wrong, please try again!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
}

void InvoiceDetailController::updateExistInvoiceDetail(InvoiceDetail data)
{
    try
    {
        this->invoiceDetailService->update(data);
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

void InvoiceDetailController::removeInvoiceDetail(InvoiceDetail data)
{
    try
    {
        this->invoiceDetailService->remove(data);
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

LinkedList<InvoiceDetail> *InvoiceDetailController::getListInvoice()
{
    try
    {
        return this->invoiceDetailService->readAll();
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

InvoiceDetail *InvoiceDetailController::getInvoiceDetailByDetailId(QString id)
{
    try
    {
        return this->invoiceDetailService->readById(id);
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

InvoiceDetailController::~InvoiceDetailController()
{
}
