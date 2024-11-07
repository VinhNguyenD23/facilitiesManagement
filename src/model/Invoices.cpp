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
        qDebug() << field;
        if (field.size() != 4)
        {
            throw DatabasesException::DatabaseBroken("invoice");
        }
        Invoice tempInvoice;
        Date tempDate;
        tempInvoice.id = field[0];
        QStringList fieldDate = field[1].split('/');
        qDebug() << fieldDate;
        tempDate = Date(fieldDate[0].toInt(), fieldDate[1].toInt(), fieldDate[2].toInt());
        tempInvoice.date = tempDate;
        tempInvoice.staffId = field[2];
        tempInvoice.type = field[3].toInt();
        this->data->add(tempInvoice);
    }
    file.close();
}

InvoiceModel::InvoiceModel()
{
    this->readFile();
}

LinkedList<Invoice> *InvoiceModel::getListData()
{
    return this->data;
}

void InvoiceModel::insertData(Invoice data)
{
    this->data->add(data);
}

void InvoiceModel::removeData(Invoice data)
{
    this->data->deleteData(data);
}

void InvoiceModel::updateData(Invoice data)
{
    // TODO: Find data and update data
    if (this->getDataById(data.id) == nullptr)
    {
        throw std::out_of_range("[ERROR] Data not found.");
    }
}

void InvoiceModel::refreshData()
{
    this->data->clear();
    this->readFile();
}

Invoice *InvoiceModel::getDataById(QString id)
{
    auto *temp = this->data->getData();
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->data.id == id)
        {
            return &temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

size_t InvoiceModel::getSize()
{
    return this->data->getSize();
}

InvoiceModel::~InvoiceModel()
{
}