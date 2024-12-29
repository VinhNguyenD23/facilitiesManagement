#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../datatype/Pair.h"
#include "invoiceform.h"
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>

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
    this->statistic = new StatisticController();

    ui->mainTab->setCurrentIndex(0);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->statisticToDate->setDateTime(currentDateTime);
    ui->toDate->setDateTime(currentDateTime);

    ui->statisticFromDate->setDateTime(currentDateTime.addDays(-31));
    ui->fromDate->setDateTime(currentDateTime.addDays(-31));

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
    staffTempTable->setColumnWidth(2, 210);
    staffTempTable->setColumnWidth(3, 195);
    staffTempTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    staffTempTable->setSelectionMode(QAbstractItemView::SingleSelection);
    staffTempTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadStaffData(staffTempTable);

    QTableWidget *statisticYearTableTemp = ui->statisticYearTable;
    statisticYearTableTemp->verticalHeader()->setVisible(false);
    statisticYearTableTemp->horizontalHeader()->setVisible(false);
    statisticYearTableTemp->setColumnCount(2);
    statisticYearTableTemp->setColumnWidth(0, 425);
    statisticYearTableTemp->setColumnWidth(1, 640);
    statisticYearTableTemp->setSelectionBehavior(QAbstractItemView::SelectRows);
    statisticYearTableTemp->setSelectionMode(QAbstractItemView::SingleSelection);
    statisticYearTableTemp->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidget *statisticTimeTableTemp = ui->statisticTimeTable;
    statisticTimeTableTemp->verticalHeader()->setVisible(false);
    statisticTimeTableTemp->horizontalHeader()->setVisible(false);
    statisticTimeTableTemp->setColumnCount(5);
    statisticTimeTableTemp->setColumnWidth(0, 215);
    statisticTimeTableTemp->setColumnWidth(1, 210);
    statisticTimeTableTemp->setColumnWidth(2, 215);
    statisticTimeTableTemp->setColumnWidth(3, 210);
    statisticTimeTableTemp->setColumnWidth(4, 210);
    statisticTimeTableTemp->setSelectionBehavior(QAbstractItemView::SelectRows);
    statisticTimeTableTemp->setSelectionMode(QAbstractItemView::SingleSelection);
    statisticTimeTableTemp->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadStatisticTimeTableData(statisticTimeTableTemp);

    QTableWidget *statisticFacilityTableTemp = ui->statisticFacilityTable;
    statisticFacilityTableTemp->verticalHeader()->setVisible(false);
    statisticFacilityTableTemp->horizontalHeader()->setVisible(false);
    statisticFacilityTableTemp->setColumnCount(5);
    statisticFacilityTableTemp->setColumnWidth(0, 355);
    statisticFacilityTableTemp->setColumnWidth(1, 355);
    statisticFacilityTableTemp->setColumnWidth(2, 355);
    statisticFacilityTableTemp->setSelectionBehavior(QAbstractItemView::SelectRows);
    statisticFacilityTableTemp->setSelectionMode(QAbstractItemView::SingleSelection);
    statisticFacilityTableTemp->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->loadStatisticFacilityTableData(statisticFacilityTableTemp);

    this->ui->statisticYearline->setText(QString::number(QDate::currentDate().year()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::loadAvlData(QTableWidget *table,
                             AVLTree<Facility, QString>::Node *node, int &row)
{
    if (!ValidateUtil::isNull(node))
    {
        table->insertRow(row);
        loadAvlData(table, node->left, row);
        QTableWidgetItem *facilityId = new QTableWidgetItem(node->data.id);
        QTableWidgetItem *facilityName = new QTableWidgetItem(node->data.name);
        QTableWidgetItem *facilityUnit = new QTableWidgetItem(node->data.unit);
        QTableWidgetItem *facilityQuantity =
            new QTableWidgetItem(QString::number(node->data.quantity));
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
    AVLTree<Facility, QString>::Node *current =
        this->facility->getListFacilities()->getList();
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
        QTableWidgetItem *staffId = new QTableWidgetItem(data->at(i)->id);
        QTableWidgetItem *staffLastName =
            new QTableWidgetItem(data->at(i)->lastName);
        QTableWidgetItem *staffFirstName =
            new QTableWidgetItem(data->at(i)->firstName);
        QTableWidgetItem *staffGender =
            new QTableWidgetItem(data->at(i)->gender ? "Nam" : "Nữ");
        table->setItem(i, 0, staffId);
        table->setItem(i, 1, staffLastName);
        table->setItem(i, 2, staffFirstName);
        table->setItem(i, 3, staffGender);
    }
}

void MainWindow::loadStatisticTimeTableData(QTableWidget *table)
{
    table->clearFocus();
    table->setRowCount(0);
    table->clearContents();
    int row = 0;
    DArray<Staff> getList = this->statistic->getStatisticInvoiceByTime(ui->fromDate->date(), ui->toDate->date());
    // qDebug() << ui->fromDate->date() << ui->toDate->date();
    for(int index = 0; index < getList.getSize(); index++)
    {
        auto *getInvoiceList = getList.at(index).invoicesList;
        if(!ValidateUtil::isNull(getInvoiceList))
        {
            auto *head = getInvoiceList->getList();
            while(!ValidateUtil::isNull(head))
            {
                table->insertRow(row);
                QTableWidgetItem *invoiceId = new QTableWidgetItem(head->data.id);
                QString getDateOfInvoice = head->data.date.getFormatValue();
                QTableWidgetItem *dateOfInvoice = new QTableWidgetItem(getDateOfInvoice);
                QTableWidgetItem *invoiceType = new QTableWidgetItem(head->data.type? "Nhập" : "Xuất");
                QString staffName = getList.at(index).lastName + ' ' + getList.at(index).firstName;
                QTableWidgetItem *toNameOfStaff = new QTableWidgetItem(staffName);
                QTableWidgetItem *invoiceValue = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(InvoiceModel::getSumOfInvoice(head->data.id), 'f', 0)));
                table->setItem(row, 0, invoiceId);
                table->setItem(row, 1, dateOfInvoice);
                table->setItem(row, 2, invoiceType);
                table->setItem(row, 3, toNameOfStaff);
                table->setItem(row, 4, invoiceValue);
                // qDebug() << head->data.id << getDateOfInvoice << (head->data.type? "Nhập" : "Xuất") << staffName << StringUtil::formatNumberWithCommas(QString::number(InvoiceModel::getSumOfInvoice(head->data.id), 'f', 0));
                // qDebug() << invoiceId->text() << dateOfInvoice->text() << invoiceType->text() << toNameOfStaff->text() << invoiceValue->text();
                head = head->next;
                row++;
            }
        }
    }
}

void MainWindow::loadStatisticYearTableData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    QString getCurrentYear = ui->statisticYearline->text();
    bool ok = false;
    int year = getCurrentYear.toInt(&ok);
    if (ok)
    {
        DArray<double> monthlyRevenue = this->statistic->getStatisticInvoiceOfYear(year);
        int row = 0;
        for (int i = 1; i <= 12; i++)
        {
            table->insertRow(row);
            QTableWidgetItem *month = new QTableWidgetItem("Tháng " + QString::number(i));
            QTableWidgetItem *revenue = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(monthlyRevenue.at(i), 'f', 0)));
            table->setItem(row, 0, month);
            table->setItem(row, 1, revenue);
            row++;
        }
    }
}

void MainWindow::loadStatisticFacilityTableData(QTableWidget *table)
{
    table->clearContents();
    table->setRowCount(0);
    DArray<Pair<QString, double>> data = this->statistic->getStatisticFacilityByTime(ui->statisticFromDate->date(), ui->statisticToDate->date());
    for (int index = 0; index < (data.getSize() < 10 ? data.getSize() : 10); index++)
    {
        table->insertRow(index);
        QTableWidgetItem *facilityId = new QTableWidgetItem(data.at(index).getFirst());
        QTableWidgetItem *facilityName = new QTableWidgetItem(this->facility->getFacilityById(data.at(index).getFirst())->name);
        QTableWidgetItem *facilityPrice = new QTableWidgetItem(StringUtil::formatNumberWithCommas(QString::number(data.at(index).getSecond(), 'f', 0)));
        table->setItem(index, 0, facilityId);
        table->setItem(index, 1, facilityName);
        table->setItem(index, 2, facilityPrice);
    }
}

void MainWindow::cleanContentFacilityTextBox()
{
    this->ui->facilityId->setText("");
    this->ui->facilityName->setText("");
    this->ui->facilityQuantity->setText("");
    this->ui->facilityUnit->setText("");
}

void MainWindow::cleanContentStaffTextBox()
{
    this->ui->staffIdTxt->setText("");
    this->ui->staffFirstNameTxt->setText("");
    this->ui->staffLastNameTxt->setText("");
    this->ui->maleRButton->setChecked(false);
    this->ui->femaleRButton->setChecked(false);
}

void MainWindow::loadTableData()
{
    this->loadFacilityData(ui->facilityTable);
    this->loadStaffData(ui->staffTable);
    this->loadStatisticFacilityTableData(ui->statisticFacilityTable);
    this->loadStatisticTimeTableData(ui->statisticTimeTable);
    this->loadStatisticYearTableData(ui->statisticYearTable);
}

void MainWindow::on_facilityTable_cellClicked(int row, int column)
{
    ui->facilityId->setText(
        ui->facilityTable->item(ui->facilityTable->currentRow(), 0)->text());
    ui->facilityName->setText(
        ui->facilityTable->item(ui->facilityTable->currentRow(), 1)->text());
    ui->facilityUnit->setText(
        ui->facilityTable->item(ui->facilityTable->currentRow(), 2)->text());
    ui->facilityQuantity->setText(
        ui->facilityTable->item(ui->facilityTable->currentRow(), 3)->text());
}

void MainWindow::on_facilityAddButton_clicked()
{
    if (ui->facilityId->toPlainText() == "" ||
        ui->facilityName->toPlainText() == "" ||
        ui->facilityUnit->toPlainText() == "" ||
        ui->facilityQuantity->toPlainText() == "")
    {
        QMessageBox msgBox;
        msgBox.setText("Bạn chưa nhập hết thông tin, vui lòng thử lại!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    bool ok;
    Facility data = Facility();
    data.id = ui->facilityId->toPlainText();
    data.name = ui->facilityName->toPlainText();
    data.unit = ui->facilityUnit->toPlainText();
    data.quantity = ui->facilityQuantity->toPlainText().toLong(&ok);
    if (!ok)
    {
        QMessageBox msgBox;
        msgBox.setText("Lỗi định dạng khi chuyển đổi số, vui lòng thử lại!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->facility->createNewFacility(data);
    this->loadTableData();
    this->cleanContentFacilityTextBox();
}

void MainWindow::on_facilityDeleteButton_clicked()
{
    QString facilityId = ui->facilityId->toPlainText();
    Facility facility = Facility();
    facility.id = facilityId;
    this->facility->removeFacility(facility);
    this->loadTableData();
    this->cleanContentFacilityTextBox();
}

void MainWindow::on_facilityEditButton_clicked()
{
    bool ok;
    Facility facilityEdit = Facility();
    facilityEdit.id = ui->facilityId->toPlainText();
    facilityEdit.name = ui->facilityName->toPlainText();
    facilityEdit.unit = ui->facilityUnit->toPlainText();
    facilityEdit.quantity = ui->facilityQuantity->toPlainText().toLong(&ok);
    if (!ok)
    {
        QMessageBox msgBox;
        msgBox.setText("Lỗi định dạng khi chuyển đổi số, vui lòng thử lại!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    if (this->facility->getFacilityById(facilityEdit.id)->quantity == facilityEdit.quantity)
    {
        this->facility->updateExistFacility(facilityEdit);
        this->loadTableData();
        this->cleanContentFacilityTextBox();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Bạn không thể thay đổi số lượng của vật tư!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
    }
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
    this->staff->create(currentStaff);
    this->loadTableData();
    this->cleanContentStaffTextBox();
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
    this->loadTableData();
    this->cleanContentStaffTextBox();
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
    this->loadTableData();
    this->cleanContentStaffTextBox();
}

void MainWindow::on_fromDate_dateTimeChanged(const QDateTime &dateTime)
{
    if (this->ui->fromDate->dateTime() > this->ui->toDate->dateTime())
    {
        qDebug() << this->ui->fromDate->dateTime() << this->ui->toDate->dateTime();
        QMessageBox msgBox;
        msgBox.setText("Sai logic!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->loadTableData();
}

void MainWindow::on_toDate_dateTimeChanged(const QDateTime &dateTime)
{
    if (this->ui->fromDate->dateTime() > this->ui->toDate->dateTime())
    {
        QMessageBox msgBox;
        msgBox.setText("Sai logic!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->loadTableData();
}

void MainWindow::on_statisticYearline_textChanged(const QString &arg1)
{
    this->loadStatisticYearTableData(ui->statisticYearTable);
}

void MainWindow::on_staffTable_cellDoubleClicked(int row, int column)
{
    QString staffId = this->ui->staffIdTxt->toPlainText();
    if (!ValidateUtil::isNull(this->staff->getStaffById(staffId)))
    {
        try {
            InvoiceForm *invoice = new InvoiceForm(nullptr, staffId, this->invoice, this->facility, this->invoiceDetail, this->staff);
            invoice->setWindowTitle("Staff ID: " + staffId);
            invoice->exec();
            this->loadTableData();
        }
        catch (const std::exception &e)
        {
            qDebug() << e.what() << '\n';
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.setIcon(QMessageBox::Icon::Critical);
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Không tìm thấy mã nhân viên " + staffId);
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
}

void MainWindow::on_statisticFromDate_dateTimeChanged(const QDateTime &dateTime)
{
    if (this->ui->statisticFromDate->dateTime() > this->ui->statisticToDate->dateTime())
    {
        qDebug() << this->ui->statisticFromDate->dateTime() << this->ui->statisticToDate->dateTime();
        QMessageBox msgBox;
        msgBox.setText("Sai logic!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->loadTableData();
}

void MainWindow::on_statisticToDate_dateTimeChanged(const QDateTime &dateTime)
{
    if (this->ui->statisticFromDate->dateTime() > this->ui->statisticToDate->dateTime())
    {
        qDebug() << this->ui->statisticFromDate->dateTime() << this->ui->statisticToDate->dateTime();
        QMessageBox msgBox;
        msgBox.setText("Sai logic!");
        msgBox.setIcon(QMessageBox::Icon::Critical);
        msgBox.exec();
        return;
    }
    this->loadTableData();
}
