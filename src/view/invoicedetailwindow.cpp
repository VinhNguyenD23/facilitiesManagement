#include "invoicedetailwindow.h"
#include "ui_invoicedetailwindow.h"
#include <qtablewidget.h>

InvoiceDetailWindow::InvoiceDetailWindow(QWidget *parent, QString invoiceId)
    : QDialog(parent)
    , ui(new Ui::InvoiceDetailWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1000, 600));
    this->invoiceId = invoiceId;
    this->invoiceDetail = new InvoiceDetailController();
    this->parent = parent;
    this->parent->hide();

    ui->InvoiceGroup->setTitle("Thông tin chi tiết hóa đơn: " + this->invoiceId);
    QTableWidget *invoiceDetailTempTable = ui->invoiceDetailTable;
    invoiceDetailTempTable->verticalHeader()->setVisible(false);
    invoiceDetailTempTable->horizontalHeader()->setVisible(false);
    invoiceDetailTempTable->setColumnCount(5);
    invoiceDetailTempTable->setColumnWidth(0, 140);
    invoiceDetailTempTable->setColumnWidth(1, 145);
    invoiceDetailTempTable->setColumnWidth(2, 145);
    invoiceDetailTempTable->setColumnWidth(3, 145);
    invoiceDetailTempTable->setColumnWidth(4, 140);
    invoiceDetailTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    invoiceDetailTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    invoiceDetailTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadDataInvoiceDetail(invoiceDetailTempTable);
}

void InvoiceDetailWindow::loadDataInvoiceDetail(QTableWidget *table)
{
    int row = 0;
    auto *current = this->invoiceDetail->getListInvoice()->getListData();
    while(current != nullptr)
    {
        if(current->data.invoiceId == this->invoiceId)
        {
            table->insertRow(row);
            QTableWidgetItem *invoiceDetailId = new QTableWidgetItem(current->data.invoiceId);
            QTableWidgetItem *facilityName = new QTableWidgetItem(current->data.facilityId);
            QTableWidgetItem *facilityQuantity = new QTableWidgetItem(QString::number(current->data.quantity));
            QTableWidgetItem *invoiceDetailPrice = new QTableWidgetItem(QString::number(current->data.price));
            QTableWidgetItem *invoiceDetailVAT = new QTableWidgetItem(QString::number(current->data.vat));

            table->setItem(row, 0, invoiceDetailId);
            table->setItem(row, 1, facilityName);
            table->setItem(row, 2, facilityQuantity);
            table->setItem(row, 3, invoiceDetailPrice);
            table->setItem(row, 4, invoiceDetailVAT);

            row++;
        }
        current = current->next;
    }
}

InvoiceDetailWindow::~InvoiceDetailWindow()
{
    this->parent->show();
    delete ui;
}
