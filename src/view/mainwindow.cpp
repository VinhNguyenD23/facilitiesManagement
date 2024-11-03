#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1150, 670));
    this->setWindowTitle("Phần mềm quản lý vật tư");
}

MainWindow::~MainWindow()
{
    delete ui;
}
