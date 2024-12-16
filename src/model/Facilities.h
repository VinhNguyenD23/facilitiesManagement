#ifndef FACILITIES_H
#define FACILITIES_H

#include "../object/facility.h"
#include "../datatype/Avl.h"
#include <QString>
#include <QFile>
#include <QDebug>
class FacilitiesModel
{
private:
    AVLTree<Facility, QString> *data;

private:
    void writeNode(AVLTree<Facility, QString>::Node *root, QTextStream &out);
    void readFile();
    void writeFile();

public:
    FacilitiesModel();
    ~FacilitiesModel();
    AVLTree<Facility, QString> *getList();
    void push(Facility data);
    void update(Facility data);
    void remove(QString id);
    void refresh();
    Facility *findByDataId(QString id);

};

#endif // FACILITIES_H
