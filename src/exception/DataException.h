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
        return DataException("[ERROR] DataException: " + message);
    }
};

#endif