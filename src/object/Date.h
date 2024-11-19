#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QStringList>
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

    Date(QString date)
    {
        QStringList listData = date.split('/');
        this->day = listData[0].toInt();
        this->month = listData[1].toInt();
        this->year = listData[2].toInt();
    }

    QString getFormatValue()
    {
        QString date;
        date = StringUtil::formatNumber(this->day) + '/' + StringUtil::formatNumber(this->month) + '/' + StringUtil::formatNumber(this->year);
        return date;
    }

    QString toRawData()
    {
        QString date;
        date = StringUtil::formatNumber(this->year) + '/' + StringUtil::formatNumber(this->month) + '/' + StringUtil::formatNumber(this->day);
        return date;
    }
};

#endif
