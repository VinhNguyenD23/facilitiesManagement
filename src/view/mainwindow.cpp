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

    QTableWidget *facilityTempTable = ui->facilityTable;
    facilityTempTable->verticalHeader()->setVisible(false);
    facilityTempTable->horizontalHeader()->setVisible(false);
    facilityTempTable->setColumnCount(4);
    facilityTempTable->setColumnWidth(0, 205);
    facilityTempTable->setColumnWidth(1, 205);
    facilityTempTable->setColumnWidth(2, 205);
    facilityTempTable->setColumnWidth(3, 200);
    facilityTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    facilityTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    facilityTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadFacilityDataStartUp(facilityTempTable);
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
}

void MainWindow::loadInvoiceDataStartUp(QTableWidget *table)
{
}

void MainWindow::loadInvoiceDetailDataStartUp(QTableWidget *table)
{
}
