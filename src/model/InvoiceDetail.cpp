#include "InvoiceDetail.h"
#include "Invoices.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../common/FilePath.h"
#include "GlobalModel.h"
#include "../util/ValidateUtil.h"

void InvoiceDetailModel::readFile()
{
    QFile file(FilePath::getPath(FilePath::databases::INVOICEDETAIL));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoiceDetail");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        InvoiceDetail *tempInvoiceDetail = new InvoiceDetail();
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 6)
        {
            throw DatabasesException::DatabaseBroken("invoiceDetail");
        }
        // tempInvoiceDetail = InvoiceDetail();
        tempInvoiceDetail->id = field[0];
        tempInvoiceDetail->invoiceId = field[1];
        tempInvoiceDetail->facilityId = field[2];
        tempInvoiceDetail->quantity = field[3].toInt();
        tempInvoiceDetail->price = field[4].toLong();
        tempInvoiceDetail->vat = (double)(field[5].toDouble() / 100.0);
        this->data->add(*tempInvoiceDetail);
        // this->push(*tempInvoiceDetail);
    }
    qDebug() << "InvoiceDetail Databases load:" << this->getSize();
    file.close();
}

void InvoiceDetailModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::INVOICEDETAIL));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoiceDetail");
    }
    QTextStream out(&file);
    auto *currentHead = this->getList();
    while (!ValidateUtil::isNull(currentHead))
    {
        out << currentHead->data.id << ',' << currentHead->data.invoiceId << ',' << currentHead->data.facilityId << ',' << QString::number(currentHead->data.quantity) << ',' << QString::number(currentHead->data.price) << ',' << QString::number(currentHead->data.vat * 100.0) << '\n';
        currentHead = currentHead->next;
    }
    file.close();
}

InvoiceDetailModel::InvoiceDetailModel()
{
    this->data = new LinkedList<InvoiceDetail>();
    this->readFile();
}

LinkedList<InvoiceDetail>::Node *InvoiceDetailModel::getList()
{
    return this->data->getList();
}

void InvoiceDetailModel::push(InvoiceDetail &data)
{
    if (ValidateUtil::isBlank(data.invoiceId) || ValidateUtil::isBlank(data.facilityId) || ValidateUtil::isBlank(data.id))
    {
        throw DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    }
    if (ValidateUtil::isNull(this->invoiceRepository))
    {
        this->invoiceRepository = invoiceModel;
    }
    this->data->add(data);
    // this->invoiceRepository->findById(data.invoiceId)->invoiceDetailList->add(data);
    this->invoiceRepository->loadInvoiceDetailData();
    this->writeFile();
}

void InvoiceDetailModel::remove(InvoiceDetail &data)
{
    if (ValidateUtil::isBlank(data.id))
    {
        throw DataException::CantHandle("Id must not be blank, please try again!");
    }
    if (ValidateUtil::isNull(this->invoiceRepository))
    {
        this->invoiceRepository = invoiceModel;
    }
    this->data->remove(data);
    this->invoiceRepository->refreshInvoiceDetail();
    this->writeFile();
}

void InvoiceDetailModel::update(InvoiceDetail &data)
{
    if (ValidateUtil::isBlank(data.invoiceId) || ValidateUtil::isBlank(data.facilityId) || ValidateUtil::isBlank(data.id))
    {
        throw DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    }
    LinkedList<InvoiceDetail>::Node *element = this->data->getElement(data);
    if (ValidateUtil::isNull(element))
    {
        throw DataException::DataNotFound("Invoice detail data not found");
    }
    qDebug() << "InvoiceDetail data address pointer: " << &element->data;
    element->data = data;
    this->writeFile();
}

void InvoiceDetailModel::refresh()
{
    this->data->clear();
    this->readFile();
}

InvoiceDetail *InvoiceDetailModel::findById(QString id)
{
    auto *temp = this->data->getList();
    while (!ValidateUtil::isNull(temp))
    {
        if (temp->data.id == id)
        {
            InvoiceDetail *invoiceData = new InvoiceDetail(temp->data);
            return invoiceData;
            // return &temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool InvoiceDetailModel::isFacilityAvailable(QString facilityId)
{
    auto *temp = this->data->getList();
    while (!ValidateUtil::isNull(temp))
    {
        if (temp->data.facilityId == facilityId)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

size_t InvoiceDetailModel::getSize()
{
    return this->data->getSize();
}

InvoiceDetailModel::~InvoiceDetailModel()
{
}
