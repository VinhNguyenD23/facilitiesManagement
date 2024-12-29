#include "invoiceform.h"
#include "ui_invoiceform.h"
#include "invoicedetailwindow.h"

InvoiceForm::InvoiceForm(QWidget *parent,
                         QString staffId,
                         InvoiceController *invoice,
                         FacilityController *facility,
                         InvoiceDetailController *invoiceDetail,
                         StaffController *staff)
    : QDialog(parent), ui(new Ui::InvoiceForm)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1000, 600));
    this->invoice = invoice;
    this->staffId = staffId;
    this->facility = facility;
    this->staff = staff;
    this->invoiceDetail = invoiceDetail;
    ui->invoiceGroup->setTitle("Hoá đơn của nhân viên ID: " + this->staffId);
    QTableWidget *invoiceTempTable = ui->InvoiceTable;
    invoiceTempTable->verticalHeader()->setVisible(false);
    invoiceTempTable->horizontalHeader()->setVisible(false);
    invoiceTempTable->setColumnCount(4);
    invoiceTempTable->setColumnWidth(0, 175);
    invoiceTempTable->setColumnWidth(1, 175);
    invoiceTempTable->setColumnWidth(2, 175);
    invoiceTempTable->setColumnWidth(3, 170);
    invoiceTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    invoiceTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    invoiceTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadInvoiceData(invoiceTempTable);

    ui->invoiceDate->setDateTime(QDateTime::currentDateTime());
}

void InvoiceForm::loadInvoiceData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    int row = 0;
    auto *getInvoiceList = this->staff->getStaffById(this->staffId)->invoicesList;
    if (!ValidateUtil::isNull(getInvoiceList))
    {
        auto *current = this->staff->getStaffById(this->staffId)->invoicesList->getList();
        while (!ValidateUtil::isNull(current))
        {
            table->insertRow(row);
            QTableWidgetItem *invoiceId = new QTableWidgetItem(current->data.id);
            QTableWidgetItem *invoiceDate = new QTableWidgetItem(current->data.date.getFormatValue());
            QTableWidgetItem *invoiceType = new QTableWidgetItem(current->data.type ? "Nhập" : "Xuất");
            QTableWidgetItem *invoicePrice = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(this->invoice->getSumOfInvoice(staffId, current->data.id), 'f', 0)));
            table->setItem(row, 0, invoiceId);
            table->setItem(row, 1, invoiceDate);
            table->setItem(row, 2, invoiceType);
            table->setItem(row, 3, invoicePrice);
            row++;
            current = current->next;
        }
    }
}

InvoiceForm::~InvoiceForm()
{
    delete ui;
}

void InvoiceForm::cleanContentInvoiceTextBox()
{
    this->ui->invoiceExport->setChecked(false);
    this->ui->invoiceImport->setChecked(false);
    this->ui->invoiceId->setText("");
    this->ui->invoiceDate->setDate(QDate().currentDate());
}

void InvoiceForm::on_invoiceAddButton_clicked()
{
    Invoice *invoiceRequest = new Invoice();
    invoiceRequest->id = ui->invoiceId->toPlainText();
    QString dateText = ui->invoiceDate->text();
    QStringList dateTextList = dateText.split('/');
    Date date = Date(dateTextList.at(2).toInt(), dateTextList.at(0).toInt(),
                     dateTextList.at(1).toInt());
    invoiceRequest->date = date;
    if (ui->invoiceImport->isChecked())
    {
        invoiceRequest->type = true;
    }
    else if (ui->invoiceExport->isChecked())
    {
        invoiceRequest->type = false;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Vui lòng chọn vào ô loại hoá đơn");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->invoice->createNewInvoice(staffId, *invoiceRequest);
    this->loadInvoiceData(this->ui->InvoiceTable);
    this->cleanContentInvoiceTextBox();
}

void InvoiceForm::on_invoiceDeleteButton_clicked()
{
    Invoice invoiceRequest = Invoice();
    invoiceRequest.id = ui->invoiceId->toPlainText();
    this->invoice->removeInvoice(staffId, invoiceRequest);
    this->loadInvoiceData(this->ui->InvoiceTable);
    this->cleanContentInvoiceTextBox();
}

void InvoiceForm::on_invoiceEditButton_clicked()
{
    Invoice invoiceRequest = Invoice();
    invoiceRequest.id = ui->invoiceId->toPlainText();
    QString dateText = ui->invoiceDate->text();
    QStringList dateTextList = dateText.split('/');
    Date date = Date(dateTextList.at(2).toInt(), dateTextList.at(0).toInt(),
                     dateTextList.at(1).toInt());
    invoiceRequest.date = date;
    if (ui->invoiceImport->isChecked())
    {
        invoiceRequest.type = true;
    }
    else if (ui->invoiceExport->isChecked())
    {
        invoiceRequest.type = false;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Vui lòng chọn vào ô loại hoá đơn");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->invoice->updateExistInvoice(staffId, invoiceRequest);
    this->loadInvoiceData(this->ui->InvoiceTable);
    this->cleanContentInvoiceTextBox();
}

void InvoiceForm::on_InvoiceTable_cellClicked(int row, int column)
{
    QString invoiceId = ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 0)->text();
    ui->invoiceId->setText(invoiceId);
    Invoice *data = this->invoice->getInvoiceById(invoiceId);
    Date getDate = Date(ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 1)->text());
    QDate date(getDate.year, getDate.month, getDate.day);
    ui->invoiceDate->setDate(date);
    ui->invoiceImport->setChecked(data->type);
    ui->invoiceExport->setChecked(!data->type);
}

void InvoiceForm::on_InvoiceTable_cellDoubleClicked(int row, int column)
{
    QString getInvoiceId = ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 0)->text();
    InvoiceDetailWindow *invoiceDetailForm = new InvoiceDetailWindow(this, getInvoiceId, staffId, this->facility, this->invoiceDetail, this->invoice);
    invoiceDetailForm->setAttribute(Qt::WA_DeleteOnClose);
    invoiceDetailForm->setWindowTitle("Invoice ID: " + getInvoiceId);
    invoiceDetailForm->exec();
    this->loadInvoiceData(ui->InvoiceTable);
}
