#ifndef VALIDATEUTIL_H
#define VALIDATEUTIL_H
#include <QString>


class ValidateUtil
{
public:
    bool static isBlank(QString text)
    {
        return text.isEmpty();
    }

    template<typename T>
    bool static isNull(T *data)
    {
        return data == nullptr;
    }

};

#endif // VALIDATEUTIL_H
