#ifndef STRINGUTIL_H
#define STRINGUTIL_H
#include <iostream>
#include <QString>
class StringUtil
{
private:
    QString text;

public:
    static QString formatNumber(int number)
    {
        QString Qnumber = "";
        if (number <= 9)
            Qnumber.append("0");
        Qnumber.append(QString::number(number));
        return Qnumber;
    }
};

#endif
