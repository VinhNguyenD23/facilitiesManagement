#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../object/InvoiceDetail.h"
#include "../util/ValidateUtil.h"
#include "../common/FilePath.h"
#include "../object/Date.h"
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
    while (!ValidateUtil::isNull(currentHead))
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
    if (!ValidateUtil::isNull(this->findById(data.id)))
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
    LinkedList<Invoice>::Node *element = this->data->getElement(data);
    if (ValidateUtil::isNull(element))
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
    while (!ValidateUtil::isNull(temp))
    {
        if (temp->data.id == id)
        {
            Invoice *invoiceData = new Invoice(temp->data);
            return invoiceData;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool InvoiceModel::isStaffAvailable(QString staffId)
{
    if(ValidateUtil::isNull(this->staffRepository))
    {
        this->staffRepository = staffModel;
    }
    auto *getInvoicesList = this->staffRepository->findById(staffId)->invoicesList;
    if(!ValidateUtil::isNull(getInvoicesList))
    {
        return true;
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
}

void InvoiceModel::refreshInvoiceDetail()
{
    InvoiceDetailModel *invoiceDetailRepository = invoiceDetailModel;
    if(ValidateUtil::isNull(invoiceDetailRepository))
    {
        invoiceDetailRepository = new InvoiceDetailModel();
    }
    auto *current = this->data->getList();
    while(!ValidateUtil::isNull(current))
    {
        if(!ValidateUtil::isNull(current->data.invoiceDetailList))
        {
            current->data.invoiceDetailList->clear();
        }
        current = current->next;
    }
    this->loadInvoiceDetailData();
}

InvoiceModel::~InvoiceModel()
{
    this->data->clear();
}
