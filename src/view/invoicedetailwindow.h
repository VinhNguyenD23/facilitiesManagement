#ifndef INVOICEDETAILWINDOW_H
#define INVOICEDETAILWINDOW_H

#include "../controller/InvoiceDetailController.h"
#include "../controller/FacilityController.h"
#include "../datatype/Avl.h"

#include "../util/StringUtil.h"

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
                                 InvoiceDetailController *invoiceDetail = nullptr);
    ~InvoiceDetailWindow();

private slots:
    void on_invoiceDetailTable_cellClicked(int row, int column);

    void on_invoiceDetailAddButton_clicked();

    void on_invoiceDetailDeleteButton_clicked();

    void on_invoiceDetailEditButton_clicked();

private:
    void loadDataInvoiceDetail(QTableWidget *table);
    void loadAvlData(QComboBox *box, AVLTree<Facility, QString>::Node *node);
    void loadDataComboBoxFaclities();

private:
    Ui::InvoiceDetailWindow *ui;
    QWidget *parent;
    QString invoiceId;
    FacilityController *facility;
    InvoiceDetailController *invoiceDetail = nullptr;

};

#endif // INVOICEDETAILWINDOW_H
