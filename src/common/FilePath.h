#ifndef FILE_PATH_DEFINE_H
#define FILE_PATH_DEFINE_H

#include "../exception/DatabasesException.h"
#include <QString>

class FilePath
{
public:
    enum class databases
    {
        FACILITY,
        STAFF,
        INVOICE,
        INVOICEDETAIL
    };

public:
    static QString getPath(databases typeDatabase)
    {
        switch (typeDatabase)
        {
        case databases::FACILITY:
            return "databases/facilities.csv";
        case databases::STAFF:
            return "databases/staff.csv";

        case databases::INVOICE:
            return "databases/invoice.csv";

        case databases::INVOICEDETAIL:
            return "databases/invoicedetail.csv";

        default:
            throw DatabasesException::InvalidDatabase();
        }
    }
};

#endif
