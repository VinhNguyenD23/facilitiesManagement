#ifndef DATE_H
#define DATE_H
#include <QString>
#include "../util/StringUtil.h"

struct Date
{
    int day, month, year;
    Date()
    {
    }
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    QString getFormatValue()
    {
        QString date;
        date = StringUtil::formatNumber(this->day) + '/' + StringUtil::formatNumber(this->month) + '/' + StringUtil::formatNumber(this->year);
        return date;
    }
};

#endif
