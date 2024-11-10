#ifndef FACILITIES_H
#define FACILITIES_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include "../common/FilePath.h"
#include "../exception/DatabasesException.h"
#include <QString>
#include <QFile>
#include <QDebug>
class FacilitiesModel
{
private:
    AVLTree<Facility, QString> *data;

private:
    void readFile();

public:
    FacilitiesModel();
    ~FacilitiesModel();
    AVLTree<Facility, QString> *getList();
    void update(Facility data);
    void remove(QString id);
    void refresh();
    AVLTree<Facility, QString>::Node *findByDataId(QString id);
};

#endif // FACILITIES_H
