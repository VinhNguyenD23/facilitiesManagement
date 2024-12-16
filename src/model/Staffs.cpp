#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../util/ValidateUtil.h"
#include "../util/ArrayUtil.h"
#include "GlobalModel.h"
#include "Invoices.h"
#include "Staffs.h"

void StaffsModel::readFile()
{
    QFile file(FilePath::getPath(FilePath::databases::STAFF));
    QStringList field;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("staff");
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        field = line.split(',');
        if (field.size() != 4)
        {
            throw DatabasesException::DatabaseBroken("staff");
        }
        Staff tempStaff;
        tempStaff.id = field.at(0);
        tempStaff.lastName = field.at(1);
        tempStaff.firstName = field.at(2);
        tempStaff.gender = (field.at(3).contains("1") ? true : false);
        this->push(tempStaff);
    }
    qDebug() << "Staff Databases load: " << this->getSize();
    file.close();
}
void StaffsModel::writeFile()
{
    QFile file(FilePath::getPath(FilePath::databases::STAFF));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw DatabasesException::DatabaseBroken("staff");
    }
    QTextStream out(&file);
    auto *current = this->getList();
    // qDebug() << current->getSize();
    for (int i = 0; i < current->getSize(); i++)
    {
        Staff *data = current->at(i);
        out << data->id << ',' << data->lastName << ',' << data->firstName << ',' << data->gender << '\n';
    }
    file.close();
}

StaffsModel::StaffsModel()
{
    this->data = new PointerArray<Staff>(MAX_STAFF);
    this->readFile();
    this->loadInvoiceData();
    this->refreshInvoice();
}

StaffsModel::~StaffsModel()
{
    this->data->clear();
}

PointerArray<Staff> *StaffsModel::getList()
{
    return this->data;
}

void StaffsModel::push(Staff data)
{
    if(this->findById(data.id) != nullptr)
    {
        throw DataException::DuplicateDataId("Staff id is existing, please try other id!");
    }
    this->data->push(data);
    ArrayUtil<Staff>::StaffSort(this->getList());
    this->writeFile();
}

void StaffsModel::remove(Staff data)
{
    this->data->remove(data);
    this->writeFile();
}

void StaffsModel::update(Staff data)
{
    this->data->update(data);
    this->writeFile();
}

void StaffsModel::refresh()
{
    this->data->clear();
    this->readFile();
}

Staff *StaffsModel::findById(QString id)
{
    for (int i = 0; i < this->getSize(); i++)
    {
        if (id == this->data->at(i)->id)
        {
            return this->data->at(i);
        }
    }
    return nullptr;
}

size_t StaffsModel::getSize()
{
    return this->data->getSize();
}

long StaffsModel::getMaxStaff()
{
    return MAX_STAFF;
}

void StaffsModel::loadInvoiceData()
{
    InvoiceModel *invoiceRepository = invoiceModel;
    if(ValidateUtil::isNull(invoiceRepository))
    {
        invoiceRepository = new InvoiceModel;
    }
    auto *currentInvoiceData = invoiceRepository->getList();
    while(!ValidateUtil::isNull(currentInvoiceData))
    {
        // qDebug() <<"Staff invoice data: "<< &currentInvoiceData->data;
        this->addInvoice(currentInvoiceData->data.staffId, currentInvoiceData->data);
        currentInvoiceData = currentInvoiceData->next;
    }
}

void StaffsModel::addInvoice(QString staffId, Invoice &data)
{
    auto *existingStaff = this->findById(staffId);
    if(ValidateUtil::isNull(existingStaff))
    {
        DataException::DataNotFound("Staff id: " + staffId.toStdString() + " not found");
    }
    if(ValidateUtil::isNull(existingStaff->invoicesList))
    {
        existingStaff->invoicesList = new LinkedList<Invoice>();
    }
    existingStaff->invoicesList->add(data);
    // qDebug() << data.invoiceDetailList;

}

void StaffsModel::refreshInvoice()
{
    auto *getListStaff = this->getList();
    for(int index = 0; index < getListStaff->getSize(); index++)
    {
        if(!ValidateUtil::isNull(this->data->at(index)->invoicesList))
        {
            auto *currentInvoiceData = this->data->at(index)->invoicesList->getList();
            // qDebug() << currentInvoiceData;
            while(!ValidateUtil::isNull(currentInvoiceData))
            {
                // qDebug() << &currentInvoiceData->data;
                currentInvoiceData = currentInvoiceData->next;
            }
        }

    }
}
