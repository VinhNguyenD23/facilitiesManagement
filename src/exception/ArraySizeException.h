#ifndef ARRAYSIZE_EXCEPTION_H
#define ARRAYSIZE_EXCEPTION_H

#include <stdexcept>
#include <string>

class ArraySizeException : public std::overflow_error
{
public:
    ArraySizeException(const std::string message) : std::overflow_error(message) {}
    static ArraySizeException ArrayFull(const std::string message)
    {
        return ArraySizeException("[ARRAY:SIZE.ERROR] Array is full: " + message);
    }

    static ArraySizeException ArrayEmpty(const std::string message)
    {
        return ArraySizeException("[ARRAY:SIZE.ERROR] Array is empty: " + message);
    }
};

#endif
