#ifndef FACILITIES_H
#define FACILITIES_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include "../common/FilePath.h"
#include "../exception/DatabasesException.h"
#include "../exception/DataException.h"
#include <QString>
#include <QFile>
#include <QDebug>
class FacilitiesModel
{
private:
    AVLTree<Facility, QString> *data;

private:
    void readFile();
    //TODO: writeFile()

public:
    FacilitiesModel();
    ~FacilitiesModel();
    AVLTree<Facility, QString> *getList();
    void insert(Facility data);
    void update(Facility data);
    void remove(QString id);
    void refresh();
    Facility *findByDataId(QString id);
};

#endif // FACILITIES_H
