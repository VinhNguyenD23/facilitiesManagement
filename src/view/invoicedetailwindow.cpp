#include "invoicedetailwindow.h"
#include "ui_invoicedetailwindow.h"
#include <qcombobox.h>
#include <qtablewidget.h>
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

    // this->parent->hide();

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
        if (current->data.invoiceId == this->invoiceId)
        {
            table->insertRow(row);
            Facility *getFacility = this->facility->getFacilityById(current->data.facilityId);
            QTableWidgetItem *invoiceDetailId = new QTableWidgetItem(current->data.id);
            QTableWidgetItem *facilityName = new QTableWidgetItem(getFacility->name);
            QTableWidgetItem *facilityQuantity = new QTableWidgetItem(QString::number(current->data.quantity));
            QTableWidgetItem *invoiceDetailPrice = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(current->data.price)));
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
    this->ui->invoiceDetailId->setText("");
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
    ui->invoiceDetailId->setText(facilityId);
    int indexFacility = -1;
    for (int i = 0; i < ui->facilityNameBox->count(); i++)
    {
        // qDebug() << ui->facilityNameBox->itemText(i).split('/').at(1) << ui->invoiceDetailTable->item(currentRow, 1)->text();
        if (ui->facilityNameBox->itemText(i).split('/').at(1).compare(ui->invoiceDetailTable->item(currentRow, 1)->text()) == 0)
        {
            indexFacility = i;
            break;
        }
    }
    if (indexFacility > 0)
    {
        ui->facilityNameBox->setCurrentIndex(indexFacility);
    }
    ui->facilityQuantityText->setText(ui->invoiceDetailTable->item(currentRow, 2)->text());
    ui->invoiceDetailPriceText->setText(StringUtil::formatRawNumber(ui->invoiceDetailTable->item(currentRow, 3)->text()));
    QString vat = ui->invoiceDetailTable->item(currentRow, 4)->text();
    vat.chop(1);
    vat = QString::number(vat.toDouble() / 100.0);
    ui->vatPrice->setText(vat);
}

void InvoiceDetailWindow::on_invoiceDetailAddButton_clicked()
{
    InvoiceDetail *currentInvoiceDetail = new InvoiceDetail();
    // qDebug() << "New invoice detail : " << currentInvoiceDetail;
    currentInvoiceDetail->id = ui->invoiceDetailId->toPlainText();
    currentInvoiceDetail->facilityId = ui->facilityNameBox->currentText().split('/').at(0);
    currentInvoiceDetail->invoiceId = this->invoiceId;
    currentInvoiceDetail->price = ui->invoiceDetailPriceText->toPlainText().toLongLong();
    currentInvoiceDetail->quantity = ui->facilityQuantityText->toPlainText().toInt();
    currentInvoiceDetail->vat = ui->vatPrice->toPlainText().toDouble();
    this->invoiceDetail->createNewInvoiceDetail(*currentInvoiceDetail);
    this->loadDataInvoiceDetail(ui->invoiceDetailTable);
    this->cleanContentInvoiceDetailData();
}

void InvoiceDetailWindow::on_invoiceDetailDeleteButton_clicked()
{
    InvoiceDetail currentInvoiceDetail = InvoiceDetail();
    currentInvoiceDetail.id = ui->invoiceDetailId->toPlainText();
    currentInvoiceDetail.invoiceId = this->invoiceId;
    currentInvoiceDetail.facilityId = ui->facilityNameBox->currentText().split('/').at(0);
    this->invoiceDetail->removeInvoiceDetail(currentInvoiceDetail);
    this->loadDataInvoiceDetail(ui->invoiceDetailTable);
    this->cleanContentInvoiceDetailData();
}

void InvoiceDetailWindow::on_invoiceDetailEditButton_clicked()
{
    InvoiceDetail currentInvoiceDetail = InvoiceDetail();
    currentInvoiceDetail.id = ui->invoiceDetailId->toPlainText();
    currentInvoiceDetail.facilityId = ui->facilityNameBox->currentText().split('/').at(0);
    currentInvoiceDetail.invoiceId = this->invoiceId;
    currentInvoiceDetail.price = ui->invoiceDetailPriceText->toPlainText().toLongLong();
    currentInvoiceDetail.quantity = ui->facilityQuantityText->toPlainText().toInt();
    currentInvoiceDetail.vat = ui->vatPrice->toPlainText().toDouble();
    this->invoiceDetail->updateExistInvoiceDetail(currentInvoiceDetail);
    this->loadDataInvoiceDetail(ui->invoiceDetailTable);
    this->cleanContentInvoiceDetailData();
}
