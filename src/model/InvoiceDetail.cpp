#include "InvoiceDetail.h"

const QString FILE_PATH = "databases/invoicedetail.csv";

InvoiceDetailModel::InvoiceDetailModel()
{
    this->data = new linkedList<InvoiceDetail>();
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
        InvoiceDetail tempInvoiceDetail;
        tempInvoiceDetail.id = field[0];
        tempInvoiceDetail.invoiceId = field[1];
        tempInvoiceDetail.facilityId = field[2];
        tempInvoiceDetail.quantity = field[3].toInt();
        tempInvoiceDetail.price = field[4].toLong();
        tempInvoiceDetail.vat = (double)(field[5].toDouble() / 100.0);
        this->data->add(tempInvoiceDetail);
    }
}

linkedList<InvoiceDetail> *InvoiceDetailModel::getListData()
{
    return this->data;
}

void InvoiceDetailModel::insertData(InvoiceDetail data)
{
    this->data->add(data);
}

void InvoiceDetailModel::removeData(InvoiceDetail data)
{
    this->data->deleteData(data);
}

void InvoiceDetailModel::updateData(InvoiceDetail data)
{
    // TODO: Find data and update data
}

void InvoiceDetailModel::refreshData()
{
    this->data->clear();
    this->data = new linkedList<InvoiceDetail>();
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
        InvoiceDetail tempInvoiceDetail;
        tempInvoiceDetail.id = field[0];
        tempInvoiceDetail.invoiceId = field[1];
        tempInvoiceDetail.facilityId = field[2];
        tempInvoiceDetail.quantity = field[3].toInt();
        tempInvoiceDetail.price = field[4].toLong();
        tempInvoiceDetail.vat = (double)(field[5].toDouble() / 100.0);
        this->data->add(tempInvoiceDetail);
    }
}

InvoiceDetail *InvoiceDetailModel::getDataById(QString id)
{
    return nullptr;
}

size_t InvoiceDetailModel::getSize()
{
    return this->data->getSize();
}

InvoiceDetailModel::~InvoiceDetailModel()
{
}

template <typename T>
inline void InvoiceDetailModel::linkData(T *data)
{
}
