#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1150, 670));
    this->setWindowTitle("Phần mềm quản lý vật tư");
    this->facility = new FacilityController();
    this->invoiceDetail = new InvoiceDetailController();
    this->invoice = new InvoiceController();
    this->staff = new StaffController();

    ui->mainTab->setCurrentIndex(0);

    QTableWidget *facilityTempTable = ui->facilityTable;
    facilityTempTable->verticalHeader()->setVisible(false);
    facilityTempTable->horizontalHeader()->setVisible(false);
    facilityTempTable->setColumnCount(4);
    facilityTempTable->setColumnWidth(0, 205);
    facilityTempTable->setColumnWidth(1, 205);
    facilityTempTable->setColumnWidth(2, 205);
    facilityTempTable->setColumnWidth(3, 190);
    facilityTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    facilityTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    facilityTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadFacilityData(facilityTempTable);

    QTableWidget *staffTempTable = ui->staffTable;
    staffTempTable->verticalHeader()->setVisible(false);
    staffTempTable->horizontalHeader()->setVisible(false);
    staffTempTable->setColumnCount(4);
    staffTempTable->setColumnWidth(0, 205);
    staffTempTable->setColumnWidth(1, 205);
    staffTempTable->setColumnWidth(2, 205);
    staffTempTable->setColumnWidth(3, 190);
    staffTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    staffTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    staffTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadStaffData(staffTempTable);

    QTableWidget *invoiceTempTable = ui->InvoiceTable;
    invoiceTempTable->verticalHeader()->setVisible(false);
    invoiceTempTable->horizontalHeader()->setVisible(false);
    invoiceTempTable->setColumnCount(5);
    invoiceTempTable->setColumnWidth(0, 165);
    invoiceTempTable->setColumnWidth(1, 165);
    invoiceTempTable->setColumnWidth(2, 165);
    invoiceTempTable->setColumnWidth(3, 165);
    invoiceTempTable->setColumnWidth(4, 160);
    invoiceTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    invoiceTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    invoiceTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadInvoiceData(invoiceTempTable);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->invoiceDate->setDateTime(currentDateTime);
    ui->fromDate->setDateTime(currentDateTime);
    ui->toDate->setDateTime(currentDateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAvlData(QTableWidget *table, AVLTree<Facility, QString>::Node *node, int &row)
{
    if (node != nullptr)
    {
        table->insertRow(row);
        loadAvlData(table, node->left, row);
        QTableWidgetItem *facilityId = new QTableWidgetItem(node->data.id);
        QTableWidgetItem *facilityName = new QTableWidgetItem(node->data.name);
        QTableWidgetItem *facilityUnit = new QTableWidgetItem(node->data.unit);
        QTableWidgetItem *facilityQuantity = new QTableWidgetItem(QString::number(node->data.quantity));
        table->setItem(row, 0, facilityId);
        table->setItem(row, 1, facilityName);
        table->setItem(row, 2, facilityUnit);
        table->setItem(row, 3, facilityQuantity);
        row++;
        loadAvlData(table, node->right, row);
    }
}

void MainWindow::loadFacilityData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    int row = 0;
    AVLTree<Facility, QString>::Node *current = this->facility->getListFacilities()->getList();
    this->loadAvlData(table, current, row);
}

void MainWindow::loadStaffData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    auto *data = this->staff->getListStaff();
    for (size_t i = 0; i < data->getSize(); i++)
    {
        table->insertRow(i);
        QTableWidgetItem *staffId = new QTableWidgetItem(data->at(i).id);
        QTableWidgetItem *staffLastName = new QTableWidgetItem(data->at(i).lastName);
        QTableWidgetItem *staffFirstName = new QTableWidgetItem(data->at(i).firstName);
        QTableWidgetItem *staffGender = new QTableWidgetItem(data->at(i).gender ? "Nam" : "Nữ");
        table->setItem(i, 0, staffId);
        table->setItem(i, 1, staffLastName);
        table->setItem(i, 2, staffFirstName);
        table->setItem(i, 3, staffGender);
    }
}

void MainWindow::loadInvoiceData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    int row = 0;
    auto *current = this->invoice->getListInvoices()->getListData();
    while (current != nullptr)
    {
        table->insertRow(row);
        auto staff = this->staff->getStaffById(current->data.staffId);
        // qDebug() << staff;
        QString staffName;
        staffName = staff->lastName + " " + staff->firstName;
        // qDebug() << current->data.date.day << current->data.date.month << current->data.date.year;
        QTableWidgetItem *invoiceId = new QTableWidgetItem(current->data.id);
        QTableWidgetItem *invoiceDate = new QTableWidgetItem(current->data.date.getFormatValue());
        QTableWidgetItem *invoiceStaffName = new QTableWidgetItem(staffName);
        QTableWidgetItem *invoiceType = new QTableWidgetItem(current->data.type ? "Nhập" : "Xuất");
        QTableWidgetItem *invoicePrice = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(this->invoice->getSumOfInvoice(current->data.id),'f', 0)));
        table->setItem(row, 0, invoiceId);
        table->setItem(row, 1, invoiceDate);
        table->setItem(row, 2, invoiceStaffName);
        table->setItem(row, 3, invoiceType);
        table->setItem(row, 4, invoicePrice);
        row++;
        current = current->next;
    }
}

// void MainWindow::loadInvoiceDetailData(QTableWidget *table)
// {
// }

// double MainWindow::getSumOfInvoice(QString invoiceId)
// {
//     double sum = 0.00;
//     auto *current = this->invoiceDetail->getListInvoice()->getListData();
//     while(current != nullptr)
//     {
//         if(current->data.invoiceId == invoiceId)
//         {
//             sum += double(current->data.price) + (double(current->data.price) * current->data.vat);
//         }
//         current = current->next;
//     }
//     return sum;
// }

void MainWindow::on_InvoiceTable_cellDoubleClicked(int row, int column)
{
    QString getInvoiceId = ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 0)->text();
    InvoiceDetailWindow *invoiceDetailForm = new InvoiceDetailWindow(this, getInvoiceId, this->facility, this->invoiceDetail);
    invoiceDetailForm->setAttribute(Qt::WA_DeleteOnClose);
    invoiceDetailForm->setWindowTitle("Invoice ID: " + getInvoiceId);
    invoiceDetailForm->exec();
    this->loadInvoiceData(ui->InvoiceTable);


}

void MainWindow::on_facilityTable_cellClicked(int row, int column)
{
    ui->facilityId->setText(ui->facilityTable->item(ui->facilityTable->currentRow(), 0)->text());
    ui->facilityName->setText(ui->facilityTable->item(ui->facilityTable->currentRow(), 1)->text());
    ui->facilityUnit->setText(ui->facilityTable->item(ui->facilityTable->currentRow(), 2)->text());
    ui->facilityQuantity->setText(ui->facilityTable->item(ui->facilityTable->currentRow(), 3)->text());
}

void MainWindow::on_facilityAddButton_clicked()
{
    Facility data = Facility();
    data.id = ui->facilityId->toPlainText();
    data.name = ui->facilityName->toPlainText();
    data.unit = ui->facilityUnit->toPlainText();
    data.quantity = ui->facilityQuantity->toPlainText().toLong();
    this->facility->createNewFacility(data);
    this->loadFacilityData(ui->facilityTable);
}

void MainWindow::on_InvoiceTable_cellClicked(int row, int column)
{
    QString invoiceId = ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 0)->text();
    ui->invoiceId->setText(invoiceId);
    Invoice *data = this->invoice->getInvoiceById(invoiceId);
    ui->invoiceStaffId->setText(data->staffId);
    Date getDate = Date(ui->InvoiceTable->item(ui->InvoiceTable->currentRow(), 1)->text());
    QDate date(getDate.year, getDate.month, getDate.day);
    ui->invoiceDate->setDate(date);
    ui->invoiceImport->setChecked(data->type);
    ui->invoiceExport->setChecked(!data->type);
}

void MainWindow::on_invoiceAddButton_clicked()
{
    Invoice invoiceRequest = Invoice();
    invoiceRequest.id = ui->invoiceId->toPlainText();
    invoiceRequest.staffId = ui->invoiceStaffId->toPlainText();
    QString dateText = ui->invoiceDate->text();
    QStringList dateTextList = dateText.split('/');
    Date date = Date(dateTextList.at(2).toInt(), dateTextList.at(0).toInt(), dateTextList.at(1).toInt());
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
        //TODO: MessageBox
        return;
    }
    this->invoice->createNewInvoice(invoiceRequest);
    this->loadInvoiceData(ui->InvoiceTable);
}

void MainWindow::on_invoiceDeleteButton_clicked()
{
    Invoice invoiceRequest = Invoice();
    invoiceRequest.id = ui->invoiceId->toPlainText();
    this->invoice->removeInvoice(invoiceRequest);
    this->loadInvoiceData(ui->InvoiceTable);
}


void MainWindow::on_invoiceEditButton_clicked()
{
    Invoice invoiceRequest = Invoice();
    invoiceRequest.id = ui->invoiceId->toPlainText();
    invoiceRequest.staffId = ui->invoiceStaffId->toPlainText();
    QString dateText = ui->invoiceDate->text();
    QStringList dateTextList = dateText.split('/');
    Date date = Date(dateTextList.at(2).toInt(), dateTextList.at(0).toInt(), dateTextList.at(1).toInt());
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
        //TODO: MessageBox
        return;
    }
    this->invoice->updateExistInvoice(invoiceRequest);
    this->loadInvoiceData(ui->InvoiceTable);
}


void MainWindow::on_facilityDeleteButton_clicked()
{
    QString facilityId = ui->facilityId->toPlainText();
    Facility facility = Facility();
    facility.id = facilityId;
    this->facility->removeFacility(facility);
    this->loadFacilityData(ui->facilityTable);
}


void MainWindow::on_facilityEditButton_clicked()
{
    Facility facility = Facility();
    facility.id = ui->facilityId->toPlainText();
    facility.name = ui->facilityName->toPlainText();
    facility.unit = ui->facilityUnit->toPlainText();
    facility.quantity = ui->facilityQuantity->toPlainText().toLong();
    this->facility->updateExistFacility(facility);
    this->loadFacilityData(ui->facilityTable);
}


void MainWindow::on_staffTable_cellClicked(int row, int column)
{
    int currentRow = ui->staffTable->currentRow();
    QString staffId = ui->staffTable->item(currentRow, 0)->text();
    ui->staffIdTxt->setText(staffId);
    Staff *getCurrentStaff = this->staff->getStaffById(staffId);
    ui->staffLastNameTxt->setText(getCurrentStaff->lastName);
    ui->staffFirstNameTxt->setText(getCurrentStaff->firstName);
    ui->maleRButton->setChecked(getCurrentStaff->gender);
    ui->femaleRButton->setChecked(!getCurrentStaff->gender);
}


void MainWindow::on_staffAddButton_clicked()
{
    Staff currentStaff = Staff();
    currentStaff.id = ui->staffIdTxt->toPlainText();
    currentStaff.lastName = ui->staffLastNameTxt->toPlainText();
    currentStaff.firstName = ui->staffFirstNameTxt->toPlainText();
    currentStaff.gender = ui->maleRButton->isChecked() ? true : false;
    // qDebug() << currentStaff.id << currentStaff.lastName << currentStaff.firstName << currentStaff.gender;
    this->staff->create(currentStaff);
    this->loadStaffData(ui->staffTable);
}


void MainWindow::on_staffDeleteButton_clicked()
{
    Staff currentStaff = Staff();
    currentStaff.id = ui->staffIdTxt->toPlainText();
    currentStaff.lastName = ui->staffLastNameTxt->toPlainText();
    currentStaff.firstName = ui->staffFirstNameTxt->toPlainText();
    currentStaff.gender = ui->maleRButton->isChecked() ? true : false;
    this->staff->removeStaff(currentStaff);
    this->loadStaffData(ui->staffTable);
    this->loadInvoiceData(ui->InvoiceTable);
}


void MainWindow::on_staffEditButton_clicked()
{
    Staff currentStaff = Staff();
    currentStaff.id = ui->staffIdTxt->toPlainText();
    currentStaff.lastName = ui->staffLastNameTxt->toPlainText();
    currentStaff.firstName = ui->staffFirstNameTxt->toPlainText();
    currentStaff.gender = ui->maleRButton->isChecked() ? true : false;
    this->staff->updateExistStaff(currentStaff);
    this->loadStaffData(ui->staffTable);
}

