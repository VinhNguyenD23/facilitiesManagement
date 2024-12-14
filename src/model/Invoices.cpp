#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../common/FilePath.h"
#include "Invoices.h"

void InvoiceModel::readFile()
{
    this->data = new LinkedList<Invoice>();
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
        Invoice tempInvoice;
        Date tempDate;
        tempInvoice.id = field[0];
        QStringList fieldDate = field[1].split('/');
        tempDate = Date(fieldDate[0].toInt(), fieldDate[1].toInt(), fieldDate[2].toInt());
        tempInvoice.date = tempDate;
        tempInvoice.staffId = field[2];
        tempInvoice.type = field[3].toInt();
        this->data->add(tempInvoice);
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
    auto *currentHead = this->getList()->getListData();
    while (currentHead != nullptr)
    {
        out << currentHead->data.id << ',' << currentHead->data.date.toRawData() << ',' << currentHead->data.staffId << ',' << currentHead->data.type << '\n';
        currentHead = currentHead->next;
    }
    file.close();
}

InvoiceModel::InvoiceModel()
{
    qDebug() << "Invoice model initialized successfully";
    this->readFile();
}

LinkedList<Invoice> *InvoiceModel::getList()
{
    return this->data;
}

void InvoiceModel::insert(Invoice data)
{
    if (this->findDataById(data.id) != nullptr)
    {
        throw DataException::DuplicateDataId("This ID already exists, please try again!");
    }
    this->data->add(data);
    this->writeFile();
}

void InvoiceModel::remove(Invoice data)
{
    this->data->remove(data);
    this->writeFile();
}

void InvoiceModel::update(Invoice data)
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

Invoice *InvoiceModel::findDataById(QString id)
{
    auto *temp = this->data->getListData();
    while (temp != nullptr)
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
    auto *temp = this->data->getListData();
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

InvoiceModel::~InvoiceModel()
{
}
