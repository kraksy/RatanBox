
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>

class logger
{
    public:
        enum LogLevel 
        {
            INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL, FATAL_LEVEL
        }; // so when creating a log in code , this will work as the first argument to the log function
        ~logger();
        logger();
        const char* gprint(logger::LogLevel const level, const char* message); 
        void print(logger::LogLevel const level, const char* message);
    
};

logger::logger()
{
}

logger::~logger()
{
}

void logger::print(logger::LogLevel const level, const char* message)
{
    std::cout << (level, message) << std::endl;

    //<< std::format("[{}] {} | {} | {}"), static_cast<enum>(level),     
}

const char* logger::gprint(logger::LogLevel const level, const char* message)
{
    std::cout << level + message << std::endl;
    return message;
}

#endif // LOGGER_H
