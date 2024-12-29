#include "InvoiceController.h"

InvoiceController::InvoiceController()
{
    try
    {
        this->invoiceService = new InvoiceService();
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
    }
}

void InvoiceController::createNewInvoice(QString staffId, Invoice &data)
{
    try
    {
        this->invoiceService->create(staffId, data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
    }
}

void InvoiceController::updateExistInvoice(QString staffId, Invoice &data)
{
    try
    {
        this->invoiceService->update(staffId, data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
    }
}

void InvoiceController::removeInvoice(QString staffId, Invoice &data)
{
    try
    {
        this->invoiceService->remove(staffId, data);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
    }
}

LinkedList<Invoice>::Node *InvoiceController::getListInvoices(QString staffId)
{
    try
    {
        return this->invoiceService->readAll(staffId);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
        return nullptr;
    }
}

Invoice *InvoiceController::getInvoiceById(QString id)
{
    try
    {
        return this->invoiceService->readById(id);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
        return nullptr;
    }
}

double InvoiceController::getSumOfInvoice(QString staffId, QString id)
{
    try
    {
        return this->invoiceService->getSum(staffId, id);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msg;
        msg.setText(e.what());
        msg.setIcon(QMessageBox::Icon::Critical);
        msg.exec();
        return 0.00;
    }
}

InvoiceController::~InvoiceController()
{
}
