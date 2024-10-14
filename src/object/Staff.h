#ifndef STAFF_H
#define STAFF_H

#include <iostream>

struct Staff
{
    std::string id; // Example: QL00X, TN00Y, BH00Z, TV00A
    std::string firstName;
    std::string lastName;
    bool gender;
    // TODO: Link to billing array [ priority: high ]
};

#endif