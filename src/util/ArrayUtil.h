#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H

#include "../datatype/PointerArray.h"
#include "../object/Staff.h"
#include <QDebug>

template <typename T>
class ArrayUtil
{
private:
    bool static compare(Staff *firstStaff, Staff *secondStaff)
    {
        if (firstStaff->firstName > secondStaff->firstName)
        {
            return true;
        }
        else if (firstStaff->firstName == secondStaff->firstName)
        {
            return firstStaff->lastName > secondStaff->lastName;
        }
        return false;
    }

    void static swap(T &firstObject, T &secondObject)
    {
        T tempObject = firstObject;
        firstObject = secondObject;
        secondObject = tempObject;
    }

public:
    ArrayUtil() {}
    void static StaffSort(PointerArray<Staff> *staffList)
    {
        size_t sizeOfStaff = staffList->getSize();
        for (size_t firstCompareStaff = 0; firstCompareStaff < sizeOfStaff; firstCompareStaff++)
        {
            Staff *firstStaff = staffList->at(firstCompareStaff);
            int minIndex = firstCompareStaff;
            for (size_t secondCompareStaff = firstCompareStaff + 1; secondCompareStaff < sizeOfStaff; secondCompareStaff++)
            {
                Staff *secondStaff = staffList->at(secondCompareStaff);
                if (compare(firstStaff, secondStaff))
                {
                    // ArrayUtil::swap(staffList->at(firstCompareStaff), staffList->at(secondCompareStaff));
                    minIndex = secondCompareStaff;
                }
            }
            ArrayUtil::swap(*staffList->at(firstCompareStaff), *staffList->at(minIndex));
        }
    }
};

#endif // ARRAYUTIL_H
