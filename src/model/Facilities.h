#ifndef FACILITIES_H
#define FACILITIES_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include "../common/FilePath.h"
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
    AVLTree<Facility, QString> *getListData();
    void updateData(Facility data);
    void removeData(QString id);
    void refreshData();
    AVLTree<Facility, QString>::Node *findByDataId(QString id);
};

#endif // FACILITIES_H
