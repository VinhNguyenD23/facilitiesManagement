#ifndef DATE_H
#define DATE_H
#include <QString>

struct Date
{
    int day, month, year, hour, minute, second;
    Date()
    {
    }
    Date(int year, int month, int day, int second, int minute, int hour)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->second = second;
        this->minute = minute;
        this->hour = hour;
    }
    QString getFormatValue()
    {
        QString date;
        date = QString::number(this->year) + '/' + QString::number(this->month) + QString::number(this->day) + ' ' + QString::number(this->hour) + ':' + QString::number(this->minute) + ':' + QString::number(this->second);
        return date;
    }
};

#endif