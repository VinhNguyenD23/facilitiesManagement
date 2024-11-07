#ifndef DATABASES_EXCEPTION_H
#define DATABASES_EXCEPTION_H
#include <stdexcept>
#include <string>
class DatabasesException : public std::runtime_error
{

public:
    DatabasesException(const std::string message) : std::runtime_error(message)
    {
    }

    static DatabasesException DatabaseBroken(const std::string name)
    {
        return DatabasesException("[DATABASE.ERROR] Database broken: Database " + name + " is broken or inaccessible, please try again !");
    }

    static DatabasesException DatabaseNotFound(const std::string name)
    {
        return DatabasesException("[DATABASE.ERROR] Database not found: Database " + name + " not found, please try again !");
    }
};

#endif