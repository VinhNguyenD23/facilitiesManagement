#include "StatisticController.h"

#include <QMessageBox>

StatisticController::StatisticController()
{
    try
    {
        this->statisticService = new StatisticService();
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

DArray<double> StatisticController::getStatisticInvoiceOfYear(int year)
{
    try
    {
        return this->statisticService->statisticYear(year);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return -1;
    }
}

DArray<Invoice> StatisticController::getStatisticInvoiceByTime(QDate from, QDate to)
{
    try
    {
        return this->statisticService->statisticTime(from, to);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return -1;
    }
}

DArray<Pair<QString, double>> StatisticController::getStatisticFacilityByTime(QDate from, QDate to)
{
    try
    {
        return this->statisticService->statisticFacilityByTime(from, to);
    }
    catch (const std::exception &e)
    {
        qDebug() << e.what() << '\n';
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return -1;
    }
}
