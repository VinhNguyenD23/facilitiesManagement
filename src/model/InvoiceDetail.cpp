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

void InvoiceDetailModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::INVOICEDETAIL));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("invoiceDetail");
    }
    QTextStream out(&file);
    auto *currentHead = this->getList()->getListData();
    while (currentHead != nullptr)
    {
        out << currentHead->data.id << ',' << currentHead->data.invoiceId << ',' << currentHead->data.facilityId << ',' << QString::number(currentHead->data.quantity) << ',' << QString::number(currentHead->data.price) << ',' << QString::number(currentHead->data.vat * 100.0) << '\n';
        currentHead = currentHead->next;
    }
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
    this->writeFile();
}

void InvoiceDetailModel::remove(InvoiceDetail data)
{
    this->data->remove(data);
    this->writeFile();
}

void InvoiceDetailModel::update(InvoiceDetail data)
{
    LinkedList<InvoiceDetail>::Node *element = this->data->getElement(data);
    if (element == nullptr)
    {
        throw DataException::DataNotFound("Invoice detail data not found");
    }
    element->data = data;
    this->writeFile();
}

void InvoiceDetailModel::refresh()
{
    this->data->clear();
    this->readFile();
}

InvoiceDetail *InvoiceDetailModel::findDataById(QString id)
{
    auto *temp = this->data->getListData();
    while (temp != nullptr)
    {
        if (temp->data.id == id)
        {
            InvoiceDetail *invoiceData = new InvoiceDetail(temp->data);
            return invoiceData;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool InvoiceDetailModel::isFacilityAvailable(QString facilityId)
{
    auto *temp = this->data->getListData();
    while (temp != nullptr)
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
