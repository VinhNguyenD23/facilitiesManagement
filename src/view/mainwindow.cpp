#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../model/Staffs.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StaffsModel *staffs = new StaffsModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
}
