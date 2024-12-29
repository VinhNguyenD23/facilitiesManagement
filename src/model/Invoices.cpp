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
    // QFile file(FilePath::getPath(FilePath::databases::INVOICE));
    // QStringList field;
    // QTextStream in(&file);
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    // {
    //     throw DatabasesException::DatabaseBroken("invoice");
    // }
    // while (!in.atEnd())
    // {
    //     QString line = in.readLine();
    //     field = line.split(',');
    //     if (field.size() != 4)
    //     {
    //         throw DatabasesException::DatabaseBroken("invoice");
    //     }
    //     Invoice *tempInvoice = new Invoice();
    //     Date tempDate;
    //     tempInvoice->id = field[0];
    //     QStringList fieldDate = field[1].split('/');
    //     tempDate = Date(fieldDate[0].toInt(), fieldDate[1].toInt(), fieldDate[2].toInt());
    //     tempInvoice->date = tempDate;
    //     tempInvoice->staffId = field[2];
    //     tempInvoice->type = field[3].toInt();
    //     this->data->add(*tempInvoice);
    // }
    // qDebug() << "Invoice Databases load:" << this->getSize();
    // file.close();
}

void InvoiceModel::writeFile()
{
    // QFile file(FilePath::getPath(FilePath::databases::INVOICE));
    // if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    // {
    //     throw DatabasesException::DatabaseBroken("invoice");
    // }
    // QTextStream out(&file);
    // auto *currentHead = this->getList();
    // while (!ValidateUtil::isNull(currentHead))
    // {
    //     out << currentHead->data.id << ',' << currentHead->data.date.toRawData() << ',' << currentHead->data.staffId << ',' << currentHead->data.type << '\n';
    //     currentHead = currentHead->next;
    // }
    // file.close();
    this->getCurrentData->writeFile();
}

InvoiceModel::InvoiceModel()
{
    this->data = new LinkedList<Invoice>();
}

InvoiceModel::InvoiceModel(QString staffId)
{
    this->staffId = staffId;
    this->getCurrentData = dataModel;
    this->data = this->getCurrentData->findInvoiceListByStaffId(staffId);
}

LinkedList<Invoice>::Node *InvoiceModel::getList()
{
    if(!ValidateUtil::isNull(this->data))
        return this->data->getList();
    return nullptr;
}

void InvoiceModel::push(Invoice data)
{
    // if (ValidateUtil::isNull(this->staffRepository))
    // {
    //     this->staffRepository = staffModel;
    // }
    // if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.staffId))
    // {
    //     throw DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    // }
    // if (!ValidateUtil::isNull(this->findById(data.id)))
    // {
    //     throw DataException::DuplicateDataId("This ID already exists, please try again!");
    // }
    // this->data->add(data);
    // this->staffRepository->addInvoice(data.staffId, data);
    // this->writeFile();
    if (ValidateUtil::isBlank(data.id))
    {
        throw DataException::CantHandle( "Some field must not be blank, please try again!");
    }
    if(!ValidateUtil::isNull(this->findById(data.id)))
    {
        throw DataException::DuplicateDataId("This ID already exists, please try again!");
    }
    this->getCurrentData->pushToInvoiceListByStaffId(this->staffId, data);
}

void InvoiceModel::remove(Invoice data)
{
    // if (ValidateUtil::isNull(this->staffRepository))
    // {
    //     this->staffRepository = staffModel;
    // }
    // this->data->remove(data);
    // this->staffRepository->refreshInvoice();
    // this->writeFile();
    this->getCurrentData->removeToInvoiceListByStaffId(this->staffId, data);

}

void InvoiceModel::update(Invoice data)
{
    // if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.staffId))
    // {
    //     throw DataException::CantHandle(data.id.toStdString() + " some field must not be blank, please try again!");
    // }
    LinkedList<Invoice>::Node *element = this->data->getElement(data);
    if (ValidateUtil::isNull(element))
    {
        throw DataException::DataNotFound("Invoice data not found");
    }
    // element->data = data;
    // this->writeFile();
    this->getCurrentData->updateToInvoiceListByStaffId(this->staffId, data);
}

void InvoiceModel::refresh()
{
    this->data->clear();
    // this->getCurrentData->readFile();
}

Invoice *InvoiceModel::findById(QString id)
{
    if(ValidateUtil::isNull(this->data))
    {
        return nullptr;
    }
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

size_t InvoiceModel::getSize()
{
    return this->data->getSize();
}

InvoiceModel::~InvoiceModel()
{
    this->data->clear();
}

