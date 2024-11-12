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

void InvoiceController::createNewInvoice(Invoice data)
{
    try
    {
        this->invoiceService->create(data);
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

void InvoiceController::updateExistInvoice(Invoice data)
{
    try
    {
        this->invoiceService->update(data);
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

void InvoiceController::removeInvoice(Invoice data)
{
    this->invoiceService->remove(data);
    try
    {
        this->invoiceService->remove(data);
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

LinkedList<Invoice> *InvoiceController::getListInvoices()
{
    try
    {
        return this->invoiceService->readAll();
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

InvoiceController::~InvoiceController()
{
}
