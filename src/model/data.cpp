#include "data.h"
#include <QFile>
#include "../common/FilePath.h"
#include "../util/ValidateUtil.h"
#include <QStringList>
#include <QTextStream>
#include <QString>

Data::Data() {
    this->staffModel = new PointerArray<Staff>(500);
    this->readFile();
}

void Data::readFile()
{
    QFile file(FilePath::getPath(FilePath::databases::DATA));
    QStringList field;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("data");
    }
    QTextStream in(&file);
    Invoice *newInvoice = nullptr;
    Staff *newStaff = nullptr;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if(ValidateUtil::isBlank(line))
        {
            if(!ValidateUtil::isNull(newStaff) && !ValidateUtil::isNull(newInvoice))
                newStaff->invoicesList->add(*newInvoice);
            this->staffModel->push(*newStaff);
            newInvoice = nullptr;
            newStaff = nullptr;
            continue;
        }
        if(ValidateUtil::isNull(newStaff) && field.size() == 4)
        {
            newStaff = new Staff();
            newStaff->id = field.at(0);
            newStaff->lastName = field.at(1);
            newStaff->firstName = field.at(2);
            newStaff->gender = field.at(3).toInt();
            continue;
        }

        if(!ValidateUtil::isNull(newStaff)) //Check if staff is available
        {
            if(field.size() == 3) //Invoice
            {
                if(!ValidateUtil::isNull(newInvoice))
                {
                    newStaff->invoicesList->add(*newInvoice);
                }
                newInvoice = new Invoice();
                if(ValidateUtil::isNull(newStaff->invoicesList))
                {
                    newStaff->invoicesList = new LinkedList<Invoice>();
                }
                Date tempDate;

                newInvoice->id = field.at(0);
                QStringList fieldDate = field.at(1).split('/');
                tempDate = Date(fieldDate.at(0).toInt(), fieldDate.at(1).toInt(), fieldDate.at(2).toInt());
                newInvoice->date = tempDate;
                newInvoice->type = field.at(2).toInt();
            }
            else if(field.size() == 4) //Invoice Detail
            {
                InvoiceDetail *newInvoiceDetail = new InvoiceDetail();
                if(ValidateUtil::isNull(newInvoice->invoiceDetailList))
                {
                    newInvoice->invoiceDetailList = new LinkedList<InvoiceDetail>();
                }
                newInvoiceDetail->facilityId = field.at(0);
                newInvoiceDetail->quantity = field.at(1).toInt();
                newInvoiceDetail->price = field.at(2).toInt();
                newInvoiceDetail->vat = field.at(3).toDouble();
                newInvoice->invoiceDetailList->add(*newInvoiceDetail);
            }
        }
    }
    file.close();
}

void Data::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::DATA));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("data");
    }
    QTextStream out(&file);
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        Staff *data = this->staffModel->at(i);
        out << data->id << ',' << data->lastName << ',' << data->firstName << ',' << data->gender << '\n';
        if(!ValidateUtil::isNull(data->invoicesList))
        {
            auto *current = data->invoicesList->getList();
            while(!ValidateUtil::isNull(current))
            {
                out << current->data.id << ',' << current->data.date.toRawData() << ',' << current->data.type << '\n';
                if(!ValidateUtil::isNull(current->data.invoiceDetailList))
                {
                    auto *getInvoiceDetailCurrent = current->data.invoiceDetailList->getList();
                    while(!ValidateUtil::isNull(getInvoiceDetailCurrent))
                    {
                        out << getInvoiceDetailCurrent->data.facilityId << ',' << getInvoiceDetailCurrent->data.quantity << ',' << getInvoiceDetailCurrent->data.price << ',' << getInvoiceDetailCurrent->data.vat << '\n';
                        getInvoiceDetailCurrent = getInvoiceDetailCurrent->next;
                    }
                }
                current = current->next;
            }
        }
        out << '\n';
    }
    file.close();
}

Staff *Data::findStaffById(QString id)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(this->staffModel->at(i)->id == id)
        {
            return this->staffModel->at(i);
        }
    }
    return nullptr;
}

LinkedList<Invoice> *Data::findInvoiceListByStaffId(QString staffId)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(this->staffModel->at(i)->id == staffId)
        {
            return this->staffModel->at(i)->invoicesList;
        }
    }
    return nullptr;
}

LinkedList<InvoiceDetail> *Data::findInvoiceDetailListByInvoiceId(QString invoiceId)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(!ValidateUtil::isNull(this->staffModel->at(i)->invoicesList))
        {
            auto *current = this->staffModel->at(i)->invoicesList->getList();
            while(!ValidateUtil::isNull(current))
            {
                if(current->data.id == invoiceId)
                {
                    return current->data.invoiceDetailList;
                }
                current = current->next;
            }
        }
    }
    return nullptr;
}

PointerArray<Staff> *Data::getCurrent()
{
    return this->staffModel;
}

void Data::pushToInvoiceListByStaffId(QString staffId, Invoice data)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(this->staffModel->at(i)->id == staffId)
        {
            this->staffModel->at(i)->invoicesList->add(data);
            break;
        }
    }
    this->writeFile();
}

void Data::removeToInvoiceListByStaffId(QString staffId, Invoice data)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(this->staffModel->at(i)->id == staffId)
        {
            this->staffModel->at(i)->invoicesList->remove(data);
            break;
        }
    }
    this->writeFile();
}

void Data::updateToInvoiceListByStaffId(QString staffId, Invoice data)
{
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(this->staffModel->at(i)->id == staffId)
        {
            auto *getCurrent = this->staffModel->at(i)->invoicesList->getElement(data);
            if(ValidateUtil::isNull(getCurrent))
            {
                throw DataException::DataNotFound("Invoice data not found");
            }
            getCurrent->data.date = data.date;
            break;
        }
    }
    this->writeFile();
}

void Data::pushToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data)
{
    bool check = false;
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(!ValidateUtil::isNull(this->staffModel->at(i)->invoicesList))
        {
            auto *current = this->staffModel->at(i)->invoicesList->getList();
            while(!ValidateUtil::isNull(current))
            {
                if(current->data.id == invoiceId)
                {
                    current->data.invoiceDetailList->add(data);
                    check = true;
                    break;
                }
                current = current->next;
            }
        }
        if(check)break;
    }

}

void Data::removeToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data)
{
    bool check = false;
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(!ValidateUtil::isNull(this->staffModel->at(i)->invoicesList))
        {
            auto *current = this->staffModel->at(i)->invoicesList->getList();
            while(!ValidateUtil::isNull(current))
            {
                if(current->data.id == invoiceId)
                {
                    current->data.invoiceDetailList->remove(data);
                    check = true;
                    break;
                }
                current = current->next;
            }
        }
        if(check)break;
    }
}

void Data::updateToInvoiceDetailListByInvoiceId(QString invoiceId, InvoiceDetail data)
{
    bool check = false;
    for(int i = 0; i < this->staffModel->getSize(); i++)
    {
        if(!ValidateUtil::isNull(this->staffModel->at(i)->invoicesList))
        {
            auto *current = this->staffModel->at(i)->invoicesList->getList();
            while(!ValidateUtil::isNull(current))
            {
                if(current->data.id == invoiceId)
                {
                    current->data.invoiceDetailList->getElement(data);
                    check = true;
                    break;
                }
                current = current->next;
            }
        }
        if(check)break;
    }
}
