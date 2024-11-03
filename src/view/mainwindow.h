#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../model/Facilities.h"
#include "../model/Staffs.h"
#include "../model/InvoiceDetail.h"
#include "../model/Invoices.h"

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
    FacilitiesModel *facilitiesModel = nullptr;
    StaffsModel *staffsModel = nullptr;
    InvoiceDetailModel *invoiceDetailModel = nullptr;
    InvoiceModel *invoiceModel = nullptr;
};
#endif // MAINWINDOW_H
