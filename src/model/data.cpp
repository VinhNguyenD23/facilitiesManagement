#include "data.h"
#include <QFile>
#include "../common/FilePath.h"
#include "../util/ValidateUtil.h"
#include <QStringList>
#include <QTextStream>

Data::Data() {
    this->staffModel = new PointerArray<Staff>();
    this->readFile();
}

void Data::readFile()
{
    QFile file(FilePath::getPath(FilePath::databases::DATA));
    bool isStaff = false, isInvoice = false;
    QStringList field;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("data");
    }
    QTextStream in(&file);
    Invoice *newInvoice = nullptr;
    while(!in.atEnd())
    {
        Staff newStaff = Staff();
        QString line = in.readLine();
        field = line.split(',');
        if(field.empty())
        {
            if(!ValidateUtil::isNull(newInvoice))
                newStaff.invoicesList->add(*newInvoice);
            this->staffModel->push(newStaff);
            isStaff = false;
            isInvoice = false;
            continue;
        }
        if(!isStaff && field.size() == 4)
        {
            newStaff.id = field.at(0);
            newStaff.lastName = field.at(1);
            newStaff.firstName = field.at(2);
            newStaff.gender = field.at(3).toInt();
            isStaff = true;
            continue;
        }

        if(isStaff) //Check if staff is available
        {
            if(field.size() == 3) //Invoice
            {
                newInvoice = new Invoice();
                if(ValidateUtil::isNull(newStaff.invoicesList))
                {
                    newStaff.invoicesList = new LinkedList<Invoice>();
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
                if(ValidateUtil::isNull(newInvoice->invoiceDetailList))
                {
                    newInvoice->invoiceDetailList = new LinkedList<InvoiceDetail>();
                }
                InvoiceDetail *newInvoiceDetail = new InvoiceDetail();
                newInvoiceDetail->facilityId = field.at(0);
                newInvoiceDetail->quantity = field.at(1).toInt();
                newInvoiceDetail->price = field.at(2).toInt();
                newInvoiceDetail->vat = field.at(3).toDouble();
                newInvoice->invoiceDetailList->add(*newInvoiceDetail);
            }
        }
    }
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
                auto *getInvoiceDetailCurrent = current->data.invoiceDetailList->getList();
                while(!ValidateUtil::isNull(getInvoiceDetailCurrent))
                {
                    out << getInvoiceDetailCurrent->data.facilityId << ',' << getInvoiceDetailCurrent->data.quantity << ',' << getInvoiceDetailCurrent->data.price << ',' << getInvoiceDetailCurrent->data.vat << '\n';
                    getInvoiceDetailCurrent = getInvoiceDetailCurrent->next;
                }
                current = current->next;
            }
        }
        out << '\n';
    }
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

}

void Data::removeToInvoiceListByStaffId(QString staffId, Invoice data)
{

}

void Data::updateToInvoiceListByStaffId(QString staffId, Invoice data)
{

}

void Data::pushToInvoiceDetailListByStaffId(QString staffId, InvoiceDetail data)
{

}

void Data::removeToInvoiceDetailListByStaffId(QString staffId, InvoiceDetail data)
{

}

void Data::updateToInvoiceDetailListByStaffId(QString staffId, InvoiceDetail data)
{

}
