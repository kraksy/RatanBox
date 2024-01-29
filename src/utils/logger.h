
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>

class logger
{
private:
    enum class LogLevel 
    {
        INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL, FATAL_LEVEL
    }; // so when creating a log in code , this will work as the first argument to the log function
public:
    logger();
    ~logger();
    const char* gprint(
        LogLevel const level,
        const char* message); 
    void print(const char* message);
    
};

logger::logger()
{
}

logger::~logger()
{
}

void logger::print(const char* message)
{
    std::cout << message << std::endl;
}

const char* logger::gprint(const char* message)
{
    std::cout << message << std::endl;
    return message;
}

#endif // LOGGER_H
