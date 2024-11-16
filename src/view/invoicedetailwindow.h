#ifndef INVOICEDETAILWINDOW_H
#define INVOICEDETAILWINDOW_H

#include "../controller/InvoiceDetailController.h"

#include <QDialog>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
namespace Ui {
class InvoiceDetailWindow;
}

class InvoiceDetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceDetailWindow(QWidget *parent = nullptr, QString invoiceid = "");
    ~InvoiceDetailWindow();

private:
    void loadDataInvoiceDetail(QTableWidget *table);

private:
    Ui::InvoiceDetailWindow *ui;
    QString invoiceid;
    InvoiceDetailController *invoiceDetail = nullptr;

};

#endif // INVOICEDETAILWINDOW_H
