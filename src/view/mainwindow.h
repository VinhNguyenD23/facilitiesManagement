#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/FacilityController.h"
#include "../controller/StaffController.h"
#include "../controller/InvoiceController.h"
#include "../controller/InvoiceDetailController.h"
#include "../datatype/Avl.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_InvoiceTable_cellDoubleClicked(int row, int column);

    void on_facilityTable_cellClicked(int row, int column);

    void on_facilityAddButton_clicked();

    void on_InvoiceTable_cellClicked(int row, int column);

    void on_invoiceAddButton_clicked();

    void on_invoiceDeleteButton_clicked();

    void on_invoiceEditButton_clicked();

    void on_facilityDeleteButton_clicked();

    void on_facilityEditButton_clicked();

    void on_staffTable_cellClicked(int row, int column);

    void on_staffAddButton_clicked();

    void on_staffDeleteButton_clicked();

    void on_staffEditButton_clicked();

    void on_fromDate_dateTimeChanged(const QDateTime &dateTime);

    void on_toDate_dateTimeChanged(const QDateTime &dateTime);

    void on_facilityQuantity_textChanged();

    void on_StatisticYearline_textChanged(const QString &arg1);

private:
    void loadAvlData(QTableWidget *table, AVLTree<Facility, QString>::Node *node, int &row);
    void loadFacilityData(QTableWidget *table);
    void loadStaffData(QTableWidget *table);
    void loadInvoiceData(QTableWidget *table);
    void loadStatisticTimeTableData(QTableWidget *table);
    void loadStatisticYearTableData(QTableWidget *table);
    void loadStatisticFacilityTableData(QTableWidget *table);
    void loadTableData();

private:
    Ui::MainWindow *ui;
    FacilityController *facility = nullptr;
    InvoiceDetailController *invoiceDetail = nullptr;
    InvoiceController *invoice = nullptr;
    StaffController *staff = nullptr;
};
#endif // MAINWINDOW_H
