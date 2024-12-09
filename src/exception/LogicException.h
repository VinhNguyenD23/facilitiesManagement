#ifndef NEGATIVEVALUEEXCEPTION_H
#define NEGATIVEVALUEEXCEPTION_H

#include <stdexcept>

class LogicException : public std::logic_error
{
public:
    LogicException(std::string message) : std::logic_error(message)
    {
    }
    static LogicException NegativeValue(std::string message)
    {
        throw LogicException("[LOGIC.ERROR] Logic error: " + message);
    }
};

#endif // NEGATIVEVALUEEXCEPTION_H
