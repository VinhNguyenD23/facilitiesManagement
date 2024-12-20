#ifndef INVOICEFORM_H
#define INVOICEFORM_H

#include "../controller/InvoiceController.h"
#include "../controller/FacilityController.h"
#include "../controller/InvoiceDetailController.h"
#include "../controller/StaffController.h"
#include <QTableWidget>
#include <QDialog>
#include <QString>

namespace Ui {
class InvoiceForm;
}

class InvoiceForm : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceForm(QWidget *parent = nullptr,
                         QString staffId = "",
                         InvoiceController *invoice = nullptr,
                         FacilityController *facility = nullptr,
                         InvoiceDetailController *invoiceDetail = nullptr,
                         StaffController *staff = nullptr);
    ~InvoiceForm();

private slots:
    void on_invoiceAddButton_clicked();

    void on_invoiceDeleteButton_clicked();

    void on_invoiceEditButton_clicked();

    void on_InvoiceTable_cellClicked(int row, int column);

    void on_InvoiceTable_cellDoubleClicked(int row, int column);

private:
    void loadInvoiceData(QTableWidget *table);
    void cleanContentInvoiceTextBox();

private:
    Ui::InvoiceForm *ui;
    InvoiceController *invoice = nullptr;
    FacilityController *facility = nullptr;
    InvoiceDetailController *invoiceDetail = nullptr;
    StaffController *staff = nullptr;
    QString staffId;
};

#endif // INVOICEFORM_H
