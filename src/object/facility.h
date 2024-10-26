#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include <QString>

// TODO: Change name field this object [ priority: above normal ] [Status: DONE]
struct Facility
{
    QString id;
    QString name;
    QString unit;
    long quantity;
    // TODO: Link with billing object [ priority: high ]
};

#endif // FACILITY_H
