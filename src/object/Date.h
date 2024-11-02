#ifndef DATE_H
#define DATE_H
#include <QString>

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
        date = QString::number(this->year) + '/' + QString::number(this->month) + '/' + QString::number(this->day);
        return date;
    }
};

#endif