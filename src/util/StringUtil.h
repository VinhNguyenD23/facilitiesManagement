#ifndef STRINGUTIL_H
#define STRINGUTIL_H
#include <QString>
#include <QStringList>
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

    static QString formatNumberWithCommas(QString number)
    {
        QString formatted = number;

        for (int i = formatted.length() - 3; i > 0; i -= 3)
        {
            formatted.insert(i, ',');
        }
        return formatted;
    }

    static QString formatRawNumber(QString number)
    {
        QStringList listOfNumber = number.split(',');
        QString result = "";
        for(int i = 0; i < listOfNumber.size(); i++)
        {
            result.append(listOfNumber.at(i));
        }
        return result;
    }
};

#endif
