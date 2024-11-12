#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/FacilityController.h"
#include "../controller/InvoiceController.h"
#include "../controller/InvoiceDetailController.h"
#include "../controller/StaffController.h"

#include "../datatype/Avl.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>

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

private:
    void loadAvlData(QTableWidget *table, AVLTree<Facility, QString>::Node *node, int &row);
    void loadFacilityDataStartUp(QTableWidget *table);
    void loadStaffDataStartUp(QTableWidget *table);
    void loadInvoiceDataStartUp(QTableWidget *table);
    void loadInvoiceDetailDataStartUp(QTableWidget *table);

private:
    Ui::MainWindow *ui;
    FacilityController *facilityController = nullptr;
    InvoiceDetailController *invoiceDetailControler = nullptr;
    InvoiceController *invoiceController = nullptr;
    StaffController *staffController = nullptr;
};
#endif // MAINWINDOW_H
