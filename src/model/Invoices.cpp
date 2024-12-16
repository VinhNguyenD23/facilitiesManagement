#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../object/InvoiceDetail.h"
#include "../util/ValidateUtil.h"
#include "../common/FilePath.h"
#include "GlobalModel.h"
#include "Invoices.h"

void InvoiceModel::readFile()
{
    QFile file(FilePath::getPath(FilePath::databases::INVOICE));
    QStringList field;
    QTextStream in(&file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoice");
    }
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw DatabasesException::DatabaseBroken("invoice");
        }
        Invoice *tempInvoice = new Invoice();
        Date tempDate;
        tempInvoice->id = field[0];
        QStringList fieldDate = field[1].split('/');
        tempDate = Date(fieldDate[0].toInt(), fieldDate[1].toInt(), fieldDate[2].toInt());
        tempInvoice->date = tempDate;
        tempInvoice->staffId = field[2];
        tempInvoice->type = field[3].toInt();
        this->data->add(*tempInvoice);
        // qDebug() << field;
    }
    qDebug() << "Invoice Databases load:" << this->getSize();
    file.close();
}

void InvoiceModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::INVOICE));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoice");
    }
    QTextStream out(&file);
    auto *currentHead = this->getList();
    while (currentHead != nullptr)
    {
        out << currentHead->data.id << ',' << currentHead->data.date.toRawData() << ',' << currentHead->data.staffId << ',' << currentHead->data.type << '\n';
        currentHead = currentHead->next;
    }
    file.close();
}

InvoiceModel::InvoiceModel()
{
    this->data = new LinkedList<Invoice>();
    this->readFile();
    this->loadInvoiceDetailData();
}

LinkedList<Invoice>::Node *InvoiceModel::getList()
{
    return this->data->getList();
}

void InvoiceModel::push(Invoice &data)
{
    if (this->findById(data.id) != nullptr)
    {
        throw DataException::DuplicateDataId("This ID already exists, please try again!");
    }
    this->data->add(data);
    this->writeFile();
}

void InvoiceModel::remove(Invoice &data)
{
    this->data->remove(data);
    this->writeFile();
}

void InvoiceModel::update(Invoice &data)
{
    // TODO: Find data and update data
    // Invoice *element = this->getDataById(data.id);
    LinkedList<Invoice>::Node *element = this->data->getElement(data);
    if (element == nullptr)
    {
        throw DataException::DataNotFound("Invoice data not found");
    }
    element->data = data;
    this->writeFile();
}

void InvoiceModel::refresh()
{
    this->data->clear();
    this->readFile();
}

Invoice *InvoiceModel::findById(QString id)
{
    auto *temp = this->data->getList();
    while (temp != nullptr)
    {
        if (temp->data.id == id)
        {
            Invoice *invoiceData = new Invoice(temp->data);
            return invoiceData;
            // return &temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool InvoiceModel::isStaffAvailable(QString staffId)
{
    auto *temp = this->data->getList();
    while (temp != nullptr)
    {
        if (temp->data.staffId == staffId)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

size_t InvoiceModel::getSize()
{
    return this->data->getSize();
}

void InvoiceModel::loadInvoiceDetailData()
{
    InvoiceDetailModel *invoiceDetailRepository = invoiceDetailModel;
    if(ValidateUtil::isNull(invoiceDetailRepository))
    {
        invoiceDetailRepository = new InvoiceDetailModel();
    }
    auto *currentData = invoiceDetailRepository->getList();
    while(!ValidateUtil::isNull(currentData))
    {
        qDebug() << currentData;
        this->addInvoiceDetail(currentData->data.invoiceId, currentData->data);
        currentData = currentData->next;
    }
}

void InvoiceModel::addInvoiceDetail(QString invoiceId, InvoiceDetail &data)
{
    auto *existingData = this->findById(invoiceId);
    if(ValidateUtil::isNull(existingData))
    {
        throw DataException::DataNotFound("Invoice id " + invoiceId.toStdString() + " not found");
    }
    LinkedList<Invoice>::Node *element = this->data->getElement(*existingData);
    if(ValidateUtil::isNull(existingData->invoiceDetailList))
    {
        element->data.invoiceDetailList = new LinkedList<InvoiceDetail>();
    }
    element->data.invoiceDetailList->add(data);
    // existingData->invoiceDetailList->add(data);
    // qDebug() << "Invoice find id: " << element;
}

void InvoiceModel::refreshInvoiceDetail()
{
    InvoiceDetailModel *invoiceDetailRepository = invoiceDetailModel;
    if(ValidateUtil::isNull(invoiceDetailRepository))
    {
        invoiceDetailRepository = new InvoiceDetailModel();
    }
    auto renewData = invoiceDetailRepository->getList();
    auto *currentData = invoiceDetailRepository->getList();
    while(!ValidateUtil::isNull(currentData))
    {

        currentData = currentData->next;
    }
}

InvoiceModel::~InvoiceModel()
{
    this->data->clear();
}
