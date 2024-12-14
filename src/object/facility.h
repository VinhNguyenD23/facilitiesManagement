#ifndef FACILITY_H
#define FACILITY_H

#include <QString>

struct Facility
{
    QString id;
    QString name;
    QString unit;
    long quantity;
    bool operator==(Facility &other)
    {
        return this->id == other.id;
    }

    bool operator!=(Facility &other)
    {
        return this->id != other.id;
    }
};

#endif // FACILITY_H
