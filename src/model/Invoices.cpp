#include "Invoices.h"

const QString FILE_PATH = "database/invoice.csv";

InvoiceModel::InvoiceModel()
{
    this->data = new linkedList<Invoice>();
    QFile file(FILE_PATH);
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw new std::runtime_error("[ERROR] This database not found or broken, please try again !");
        }
        Invoice tempInvoice;
        tempInvoice.id = field[0];
    }
}

linkedList<Invoice> *InvoiceModel::getListData()
{
    return this->data;
}

void InvoiceModel::insertData(Invoice data)
{
}

void InvoiceModel::removeData(Invoice data)
{
}

void InvoiceModel::updateData(Invoice data)
{
}

void InvoiceModel::refreshData()
{
}

Invoice *InvoiceModel::getDataById(QString id)
{
}

size_t InvoiceModel::getSize()
{
    return size_t();
}

InvoiceModel::~InvoiceModel()
{
}

template <typename T>
void InvoiceModel::linkData(T *data)
{
}
