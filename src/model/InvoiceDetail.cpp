#include "InvoiceDetail.h"
#include "Invoices.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../common/FilePath.h"
#include "GlobalModel.h"
#include "../util/ValidateUtil.h"

void InvoiceDetailModel::readFile()
{
}

void InvoiceDetailModel::writeFile()
{
    this->getCurrentData->writeFile();
}

InvoiceDetailModel::InvoiceDetailModel()
{
    this->data = new LinkedList<InvoiceDetail>();
    this->readFile();
}

InvoiceDetailModel::InvoiceDetailModel(QString invoiceId)
{
    this->getCurrentData = dataModel;
    this->invoiceId = invoiceId;
    this->data = this->getCurrentData->findInvoiceDetailListByInvoiceId(invoiceId);
}

LinkedList<InvoiceDetail>::Node *InvoiceDetailModel::getList()
{
    if(!ValidateUtil::isNull(this->data))
        return this->data->getList();
    return nullptr;
}

void InvoiceDetailModel::push(InvoiceDetail data)
{
    if (ValidateUtil::isBlank(data.facilityId))
    {
        throw DataException::CantHandle("Some field must not be blank, please try again!");
    }
    this->getCurrentData->pushToInvoiceDetailListByInvoiceId(this->invoiceId, data);
    this->getCurrentData->writeFile();
}

void InvoiceDetailModel::remove(InvoiceDetail data)
{
    this->getCurrentData->removeToInvoiceDetailListByInvoiceId(this->invoiceId, data);
    this->getCurrentData->writeFile();
}

void InvoiceDetailModel::update(InvoiceDetail data)
{
    this->getCurrentData->updateToInvoiceDetailListByInvoiceId(this->invoiceId, data);
    this->getCurrentData->writeFile();
}

void InvoiceDetailModel::refresh()
{
    this->data->clear();
    // this->readFile();
}

// InvoiceDetail *InvoiceDetailModel::findById(QString id)
// {
//     auto *temp = this->data->getList();
//     while (!ValidateUtil::isNull(temp))
//     {
//         if (temp->data.id == id)
//         {
//             InvoiceDetail *invoiceData = new InvoiceDetail(temp->data);
//             return invoiceData;
//         }
//         temp = temp->next;
//     }
//     return nullptr;
// }

bool InvoiceDetailModel::isFacilityAvailable(QString facilityId)
{
    auto *temp = this->data->getList();
    while (!ValidateUtil::isNull(temp))
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

double InvoiceDetailModel::getSum(InvoiceDetail data)
{
    return double(data.price * data.quantity) * double(1.0 + data.vat);
}

InvoiceDetailModel::~InvoiceDetailModel()
{
}

QString InvoiceDetailModel::getInvoiceId()
{
    return this->invoiceId;
}
