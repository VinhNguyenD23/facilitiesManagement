#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/FacilityController.h"
#include "../controller/InvoiceController.h"
#include "../controller/InvoiceDetailController.h"
#include "../controller/StaffController.h"

#include <QMainWindow>
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
    Ui::MainWindow *ui;
    FacilityController *facilityController = nullptr;
    InvoiceDetailController *invoiceDetailControler = nullptr;
    InvoiceController *invoiceController = nullptr;
    StaffController *staffController = nullptr;
};
#endif // MAINWINDOW_H
