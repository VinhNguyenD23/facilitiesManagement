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
    Facility A;
    A.id = "123";
    A.name = "Sat";
    A.quantity = 3;
    A.unit = "Cai";
    this->facilityController->createNewFacility(A);
}

MainWindow::~MainWindow()
{
    delete ui;
}
