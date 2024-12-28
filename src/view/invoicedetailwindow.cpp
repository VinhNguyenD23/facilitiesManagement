#include "invoicedetailwindow.h"
#include "ui_invoicedetailwindow.h"
#include <qcombobox.h>
#include <QDebug>
#include <QTableWidget>
#include "../util/StringUtil.h"
#include "../util/ValidateUtil.h"

InvoiceDetailWindow::InvoiceDetailWindow(QWidget *parent,
                                         QString invoiceId,
                                         FacilityController *facility,
                                         InvoiceDetailController *invoiceDetail,
                                         InvoiceController *invoice)
    : QDialog(parent), ui(new Ui::InvoiceDetailWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1000, 600));

    this->invoiceId = invoiceId;
    this->invoiceDetail = invoiceDetail;
    this->parent = parent;
    this->facility = facility;
    this->invoice = invoice;

    ui->InvoiceGroup->setTitle("Thông tin chi tiết hóa đơn: " + this->invoiceId);
    QTableWidget *invoiceDetailTempTable = ui->invoiceDetailTable;
    invoiceDetailTempTable->verticalHeader()->setVisible(false);
    invoiceDetailTempTable->horizontalHeader()->setVisible(false);
    invoiceDetailTempTable->setColumnCount(4);
    invoiceDetailTempTable->setColumnWidth(0, 175);
    invoiceDetailTempTable->setColumnWidth(1, 175);
    invoiceDetailTempTable->setColumnWidth(2, 175);
    invoiceDetailTempTable->setColumnWidth(3, 175);
    invoiceDetailTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    invoiceDetailTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    invoiceDetailTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadDataInvoiceDetail(invoiceDetailTempTable);

    this->loadDataComboBoxFaclities();
}

void InvoiceDetailWindow::loadDataInvoiceDetail(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    int row = 0;
    auto *getInvoiceDetailList = this->invoice->getInvoiceById(this->invoiceId)->invoiceDetailList;
    if (ValidateUtil::isNull(getInvoiceDetailList))
    {
        return;
    }
    auto *current = getInvoiceDetailList->getList();
    while (!ValidateUtil::isNull(current))
    {
        table->insertRow(row);
        Facility *getFacility = this->facility->getFacilityById(current->data.facilityId);
        QTableWidgetItem *facilityName = new QTableWidgetItem(getFacility->name);
        QTableWidgetItem *facilityQuantity = new QTableWidgetItem(QString::number(current->data.quantity));
        QTableWidgetItem *invoiceDetailPrice = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(current->data.price)));
        QTableWidgetItem *invoiceDetailVAT = new QTableWidgetItem(QString::number(current->data.vat) + "%");
        table->setItem(row, 0, facilityName);
        table->setItem(row, 1, facilityQuantity);
        table->setItem(row, 2, invoiceDetailPrice);
        table->setItem(row, 3, invoiceDetailVAT);
        row++;
        current = current->next;
    }
}

void InvoiceDetailWindow::loadAvlData(QComboBox *box, AVLTree<Facility, QString>::Node *node)
{
    if (!ValidateUtil::isNull(node))
    {
        this->loadAvlData(box, node->left);
        box->addItem(node->data.id + '/' + node->data.name);
        this->loadAvlData(box, node->right);
    }
}

void InvoiceDetailWindow::loadDataComboBoxFaclities()
{
    auto *current = this->facility->getListFacilities()->getList();
    this->loadAvlData(ui->facilityNameBox, current);
}

void InvoiceDetailWindow::cleanContentInvoiceDetailData()
{
    this->ui->invoiceDetailPriceText->setText("");
    this->ui->vatPrice->setText("");
    this->ui->facilityQuantityText->setText("");
}

InvoiceDetailWindow::~InvoiceDetailWindow()
{
    this->parent->show();
    delete ui;
}

void InvoiceDetailWindow::on_invoiceDetailTable_cellClicked(int row, int column)
{
    int currentRow = ui->invoiceDetailTable->currentRow();
    QString facilityId = ui->invoiceDetailTable->item(currentRow, 0)->text();
    int indexFacility = -1;
    for (int i = 0; i < ui->facilityNameBox->count(); i++)
    {
        if (ui->facilityNameBox->itemText(i).split('/').at(1).compare(ui->invoiceDetailTable->item(currentRow, 0)->text()) == 0)
        {
            indexFacility = i;
            break;
        }
    }
    qDebug() << indexFacility;
    if (indexFacility > 0)
    {
        ui->facilityNameBox->setCurrentIndex(indexFacility);
    }
    ui->facilityQuantityText->setText(ui->invoiceDetailTable->item(currentRow, 1)->text());
    ui->invoiceDetailPriceText->setText(StringUtil::formatRawNumber(ui->invoiceDetailTable->item(currentRow, 2)->text()));
    QString vat = ui->invoiceDetailTable->item(currentRow, 3)->text();
    vat.chop(1);
    vat = QString::number(vat.toDouble());
    ui->vatPrice->setText(vat);
}

void InvoiceDetailWindow::on_invoiceDetailAddButton_clicked()
{
    InvoiceDetail *currentInvoiceDetail = new InvoiceDetail();
    currentInvoiceDetail->facilityId = ui->facilityNameBox->currentText().split('/').at(0);
    currentInvoiceDetail->price = ui->invoiceDetailPriceText->toPlainText().toLongLong();
    currentInvoiceDetail->quantity = ui->facilityQuantityText->toPlainText().toInt();
    currentInvoiceDetail->vat = ui->vatPrice->toPlainText().toDouble();
    this->invoiceDetail->createNewInvoiceDetail(*currentInvoiceDetail);
    this->loadDataInvoiceDetail(ui->invoiceDetailTable);
    this->cleanContentInvoiceDetailData();
}

// void InvoiceDetailWindow::on_invoiceDetailDeleteButton_clicked()
// {
//     InvoiceDetail currentInvoiceDetail = InvoiceDetail();
//     currentInvoiceDetail.facilityId = ui->facilityNameBox->currentText().split('/').at(0);
//     this->invoiceDetail->removeInvoiceDetail(currentInvoiceDetail);
//     this->loadDataInvoiceDetail(ui->invoiceDetailTable);
//     this->cleanContentInvoiceDetailData();
// }

// void InvoiceDetailWindow::on_invoiceDetailEditButton_clicked()
// {
//     InvoiceDetail currentInvoiceDetail = InvoiceDetail();
//     currentInvoiceDetail.facilityId = ui->facilityNameBox->currentText().split('/').at(0);
//     currentInvoiceDetail.price = ui->invoiceDetailPriceText->toPlainText().toLongLong();
//     currentInvoiceDetail.quantity = ui->facilityQuantityText->toPlainText().toInt();
//     currentInvoiceDetail.vat = ui->vatPrice->toPlainText().toDouble();
//     this->invoiceDetail->updateExistInvoiceDetail(currentInvoiceDetail);
//     this->loadDataInvoiceDetail(ui->invoiceDetailTable);
//     this->cleanContentInvoiceDetailData();
// }
