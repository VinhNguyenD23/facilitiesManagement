#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>

// TODO: Change name field this object [ priority: above normal ] [Status: DONE]
struct Facility
{
    std::string id;
    std::string name;
    std::string unit;
    long quantity;
    // TODO: Link with billing object [ priority: high ]
};

#endif // FACILITY_H
