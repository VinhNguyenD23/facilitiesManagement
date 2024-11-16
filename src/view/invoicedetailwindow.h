#ifndef INVOICEDETAILWINDOW_H
#define INVOICEDETAILWINDOW_H

#include "../controller/InvoiceDetailController.h"
#include "../controller/FacilityController.h"
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
    explicit InvoiceDetailWindow(QWidget *parent = nullptr, QString invoiceId = "", FacilityController *facility = nullptr);
    ~InvoiceDetailWindow();

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
