#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include "../util/ValidateUtil.h"
#include "../util/ArrayUtil.h"
#include "GlobalModel.h"
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
    // QFile file(FilePath::getPath(FilePath::databases::STAFF));
    // if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    // {
    //     throw DatabasesException::DatabaseBroken("staff");
    // }
    // QTextStream out(&file);
    // auto *current = this->getList();
    // for (int i = 0; i < current->getSize(); i++)
    // {
    //     Staff *data = current->at(i);
    //     out << data->id << ',' << data->lastName << ',' << data->firstName << ',' << data->gender << '\n';
    // }
    // file.close();
    getCurrentData->writeFile();
}

StaffsModel::StaffsModel()
{
    this->getCurrentData = dataModel;
    this->data = getCurrentData->getCurrent();
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
    if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.firstName) || ValidateUtil::isBlank(data.lastName))
    {
        DataException::CantHandle("Some field must not be blank, please try again!");
    }
    if (!ValidateUtil::isNull(this->findById(data.id)))
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
    if (ValidateUtil::isBlank(data.id) || ValidateUtil::isBlank(data.firstName) || ValidateUtil::isBlank(data.lastName))
    {
        DataException::CantHandle("Some field must not be blank, please try again!");
    }
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
    // return this->getCurrentData->findStaffById(id);
}

size_t StaffsModel::getSize()
{
    // return this->data->getSize();
    return this->getCurrentData->getCurrent()->getSize();
}

long StaffsModel::getMaxStaff()
{
    return MAX_STAFF;
}

// void StaffsModel::loadInvoiceData()
// {
//     InvoiceModel *invoiceRepository = invoiceModel;
//     auto *currentInvoiceData = invoiceRepository->getList();
//     while (!ValidateUtil::isNull(currentInvoiceData))
//     {
//         this->addInvoice(currentInvoiceData->data.staffId, currentInvoiceData->data);
//         currentInvoiceData = currentInvoiceData->next;
//     }
// }

// void StaffsModel::addInvoice(QString staffId, Invoice &data)
// {
//     auto *existingStaff = this->findById(staffId);
//     if (ValidateUtil::isNull(existingStaff))
//     {
//         DataException::DataNotFound("Staff id: " + staffId.toStdString() + " not found");
//     }
//     if (ValidateUtil::isNull(existingStaff->invoicesList))
//     {
//         existingStaff->invoicesList = new LinkedList<Invoice>();
//     }
//     existingStaff->invoicesList->add(data);
// }

// void StaffsModel::refreshInvoice()
// {
//     InvoiceModel *invoiceRepository = invoiceModel;
//     auto *getListStaff = this->getList();
//     for (int index = 0; index < getListStaff->getSize(); index++)
//     {
//         auto *getInvoicesList = this->data->at(index)->invoicesList;
//         if (!ValidateUtil::isNull(getInvoicesList))
//         {
//             getInvoicesList->clear();
//             getInvoicesList = nullptr;
//         }
//     }
//     this->loadInvoiceData();
// }
