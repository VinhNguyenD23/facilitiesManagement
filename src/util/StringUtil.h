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

    static QString formatNumberWithCommas(const QString &number) {
        QString formatted = number;

        // Duyệt ngược và thêm dấu phẩy sau mỗi 3 chữ số
        for (int i = formatted.length() - 3; i > 0; i -= 3) {
            formatted.insert(i, ',');
        }
        return formatted;
    }
};

#endif
