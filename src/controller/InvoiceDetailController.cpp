#include "InvoiceDetailController.h"
#include <QMessageBox>

InvoiceDetailController::InvoiceDetailController()
{
    try
    {
        this->invoiceDetailService = new InvoiceDetailService();
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

InvoiceDetailController::InvoiceDetailController(QString staffId, QString invoiceId)
{
    try
    {
        this->invoiceDetailService = new InvoiceDetailService(staffId, invoiceId);
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

// void InvoiceDetailController::updateExistInvoiceDetail(InvoiceDetail data)
// {
//     try
//     {
//         this->invoiceDetailService->update(data);
//     }
//     catch (const std::exception &e)
//     {
//         qDebug() << e.what() << '\n';
//         QMessageBox msgBox;
//         msgBox.setText(e.what());
//         msgBox.setIcon(QMessageBox::Icon::Critical);
//         msgBox.exec();
//     }
// }

// void InvoiceDetailController::removeInvoiceDetail(InvoiceDetail data)
// {
//     try
//     {
//         this->invoiceDetailService->remove(data);
//     }
//     catch (const std::exception &e)
//     {
//         qDebug() << e.what() << '\n';
//         QMessageBox msgBox;
//         msgBox.setText(e.what());
//         msgBox.setIcon(QMessageBox::Icon::Critical);
//         msgBox.exec();
//     }
// }

LinkedList<InvoiceDetail>::Node *InvoiceDetailController::getListInvoice()
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

// InvoiceDetail *InvoiceDetailController::getInvoiceDetailByDetailId(QString id)
// {
//     try
//     {
//         return this->invoiceDetailService->readById(id);
//     }
//     catch (const std::exception &e)
//     {
//         qDebug() << e.what() << '\n';
//         QMessageBox msgBox;
//         msgBox.setText(e.what());
//         msgBox.setIcon(QMessageBox::Icon::Critical);
//         msgBox.exec();
//         return nullptr;
//     }
// }

InvoiceDetailController::~InvoiceDetailController()
{
}
