#include "Invoices.h"

const QString FILE_PATH = "database/invoice.csv";

InvoiceModel::InvoiceModel()
{
    this->data = new linkedList<Invoice>();
    QFile file(FILE_PATH);
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw std::runtime_error("[ERROR] This database not found or broken, please try again !");
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
    }
}

linkedList<Invoice> *InvoiceModel::getListData()
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
}

void InvoiceModel::refreshData()
{
    this->data->clear();
    this->data = new linkedList<Invoice>();
    QFile file(FILE_PATH);
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw std::runtime_error("[ERROR] This database not found or broken, please try again !");
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
    }
}

Invoice *InvoiceModel::getDataById(QString id)
{
    return nullptr;
}

size_t InvoiceModel::getSize()
{
    return this->data->getSize();
}

InvoiceModel::~InvoiceModel()
{
}

template <typename T>
void InvoiceModel::linkData(T *data)
{
}
