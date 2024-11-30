#ifndef VALIDATEEXCEPTION_H
#define VALIDATEEXCEPTION_H

#include <stdexcept>
#include <string>

class ValidateException : public std::logic_error
{
public:
    ValidateException(const std::string message) : std::logic_error(message)
    {
    }
    static ValidateException InvalidData(const std::string message)
    {
        return ValidateException("[VALIDATE.ERROR] Invalid data: " + message);
    }
};

#endif // VALIDATEEXCEPTION_H
