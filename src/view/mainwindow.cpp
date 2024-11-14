#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1150, 670));
    this->setWindowTitle("Phần mềm quản lý vật tư");
    this->facilityController = new FacilityController();
    this->invoiceDetailControler = new InvoiceDetailController();
    this->invoiceController = new InvoiceController();
    this->staffController = new StaffController();

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
    this->loadFacilityDataStartUp(facilityTempTable);

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
    this->loadStaffDataStartUp(staffTempTable);

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
    this->loadInvoiceDataStartUp(invoiceTempTable);
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

void MainWindow::loadFacilityDataStartUp(QTableWidget *table)
{
    int row = 0;
    AVLTree<Facility, QString>::Node *current = this->facilityController->getListFacilities()->getList();
    this->loadAvlData(table, current, row);
}

void MainWindow::loadStaffDataStartUp(QTableWidget *table)
{
    auto *data = this->staffController->getListStaff();
    for(size_t i = 0; i < data->getSize(); i++)
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

void MainWindow::loadInvoiceDataStartUp(QTableWidget *table)
{
    int row = 0;
    auto *current = this->invoiceController->getListInvoices()->getListData();
    while(current != nullptr)
    {
        table->insertRow(row);
        auto staff = this->staffController->getStaffById(current->data.staffId);
        // qDebug() << staff;
        QString staffName;
        staffName = staff->lastName + " " + staff->firstName;
        QTableWidgetItem *invoiceId = new QTableWidgetItem(current->data.id);
        QTableWidgetItem *invoiceDate = new QTableWidgetItem(current->data.date.getFormatValue());
        QTableWidgetItem *invoiceStaffName = new QTableWidgetItem(staffName);
        QTableWidgetItem *invoiceType = new QTableWidgetItem(current->data.type ? "Nhập" : "Xuất");
        QTableWidgetItem *invoicePrice = new QTableWidgetItem("0");
        table->setItem(row, 0, invoiceId);
        table->setItem(row, 1, invoiceDate);
        table->setItem(row, 2, invoiceStaffName);
        table->setItem(row, 3, invoiceType);
        table->setItem(row, 4, invoicePrice);
        row++;
        current = current->next;
    }
}

void MainWindow::loadInvoiceDetailDataStartUp(QTableWidget *table)
{
}
