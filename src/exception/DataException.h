#ifndef DATA_EXCEPTION_H
#define DATA_EXCEPTION_H
#include <stdexcept>
#include <string>
class DataException : public std::runtime_error
{
public:
    DataException(const std::string message) : std::runtime_error(message)
    {
    }

    static DataException DataNotFound(const std::string message)
    {
        return DataException("[DATA.ERROR] Data not found: " + message);
    }

    static DataException DuplicateDataId(const std::string message)
    {
        return DataException("[DATA.ERROR] Duplicate data id: " + message);
    }

    static DataException ExistDataId(const std::string message)
    {
        return DataException("[DATA.ERROR] Existing data id: " + message);
    }

    static DataException CantHandle(const std::string message)
    {
        return DataException("[DATA.ERROR] Cant handle with data id: " + message);
    }
};

#endif
