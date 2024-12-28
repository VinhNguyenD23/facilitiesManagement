#ifndef INVOICEDETAILWINDOW_H
#define INVOICEDETAILWINDOW_H

#include "../controller/InvoiceDetailController.h"
#include "../controller/FacilityController.h"
#include "../controller/InvoiceController.h"
#include "../datatype/Avl.h"

#include <QDialog>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>
namespace Ui {
class InvoiceDetailWindow;
}

class InvoiceDetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceDetailWindow(QWidget *parent = nullptr,
                                 QString invoiceId = "",
                                 FacilityController *facility = nullptr,
                                 InvoiceDetailController *invoiceDetail = nullptr,
                                 InvoiceController *invoice = nullptr);
    ~InvoiceDetailWindow();

private slots:
    void on_invoiceDetailTable_cellClicked(int row, int column);

    void on_invoiceDetailAddButton_clicked();

private:
    void loadDataInvoiceDetail(QTableWidget *table);
    void loadAvlData(QComboBox *box, AVLTree<Facility, QString>::Node *node);
    void loadDataComboBoxFaclities();
    void cleanContentInvoiceDetailData();

private:
    Ui::InvoiceDetailWindow *ui;
    QWidget *parent;
    QString invoiceId;
    FacilityController *facility;
    InvoiceDetailController *invoiceDetail = nullptr;
    InvoiceController *invoice = nullptr;

};

#endif // INVOICEDETAILWINDOW_H
