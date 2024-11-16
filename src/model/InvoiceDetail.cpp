#include "InvoiceDetail.h"

void InvoiceDetailModel::readFile()
{
    this->data = new LinkedList<InvoiceDetail>();
    QFile file(FilePath::getPath(FilePath::databases::INVOICEDETAIL));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoiceDetail");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        InvoiceDetail tempInvoiceDetail;
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 6)
        {
            throw DatabasesException::DatabaseBroken("invoiceDetail");
        }
        tempInvoiceDetail = InvoiceDetail();
        tempInvoiceDetail.id = field[0];
        tempInvoiceDetail.invoiceId = field[1];
        tempInvoiceDetail.facilityId = field[2];
        tempInvoiceDetail.quantity = field[3].toInt();
        tempInvoiceDetail.price = field[4].toLong();
        tempInvoiceDetail.vat = (double)(field[5].toDouble() / 100.0);
        this->data->add(tempInvoiceDetail);
    }
    qDebug() << "InvoiceDetail Databases load:" << this->getSize();
    file.close();
}

InvoiceDetailModel::InvoiceDetailModel()
{
    qDebug() << "Invoice Detail model initialized successfully";
    this->readFile();
}

LinkedList<InvoiceDetail> *InvoiceDetailModel::getList()
{
    return this->data;
}

void InvoiceDetailModel::insert(InvoiceDetail data)
{
    this->data->add(data);
}

void InvoiceDetailModel::remove(InvoiceDetail data)
{
    this->data->remove(data);
}

void InvoiceDetailModel::update(InvoiceDetail data)
{
    LinkedList<InvoiceDetail>::Node *element = this->data->getElement(data);
    if (element == nullptr)
    {
        throw DataException::DataNotFound("Data not found");
    }
    element->data = data;
}

void InvoiceDetailModel::refresh()
{
    this->data->clear();
    this->readFile();
}

InvoiceDetail *InvoiceDetailModel::getDataById(QString id)
{
    // LinkedList<InvoiceDetail>::Node *current = this->data->getListData();
    // while (current->next != nullptr)
    // {
    // }
    return nullptr;
}

size_t InvoiceDetailModel::getSize()
{
    return this->data->getSize();
}

InvoiceDetailModel::~InvoiceDetailModel()
{
}
