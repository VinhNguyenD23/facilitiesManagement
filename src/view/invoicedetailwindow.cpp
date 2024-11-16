#include "invoicedetailwindow.h"
#include "ui_invoicedetailwindow.h"
#include <qcombobox.h>
#include <qtablewidget.h>

InvoiceDetailWindow::InvoiceDetailWindow(QWidget *parent, QString invoiceId, FacilityController *facility)
    : QDialog(parent)
    , ui(new Ui::InvoiceDetailWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1000, 600));

    this->invoiceId = invoiceId;
    this->invoiceDetail = new InvoiceDetailController();
    this->parent = parent;
    this->facility = facility;

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

    this->loadDataComboBoxFaclities();
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
            Facility *getFacility = this->facility->getFacilityById(current->data.facilityId);
            QTableWidgetItem *invoiceDetailId = new QTableWidgetItem(current->data.id);
            QTableWidgetItem *facilityName = new QTableWidgetItem(getFacility->name);
            QTableWidgetItem *facilityQuantity = new QTableWidgetItem(QString::number(current->data.quantity));
            QTableWidgetItem *invoiceDetailPrice = new QTableWidgetItem(QString::number(current->data.price));
            QTableWidgetItem *invoiceDetailVAT = new QTableWidgetItem(QString::number(current->data.vat * 100.000) + "%");

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

void InvoiceDetailWindow::loadAvlData(QComboBox *box, AVLTree<Facility, QString>::Node *node)
{
    if(node != nullptr)
    {
        this->loadAvlData(box, node->left);
        box->addItem(node->data.name);
        this->loadAvlData(box, node->right);
    }
}

void InvoiceDetailWindow::loadDataComboBoxFaclities()
{
    auto *current = this->facility->getListFacilities()->getList();
    this->loadAvlData(ui->facilityNameBox, current);
}

InvoiceDetailWindow::~InvoiceDetailWindow()
{
    this->parent->show();
    delete ui;
}
