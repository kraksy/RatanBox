
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fmt/core.h>

class logger
{
    public:
        enum LogLevel 
        {
            INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL, FATAL_LEVEL
        }; // so when creating a log in code , this will work as the first argument to the log function
        ~logger();
        logger();
        std::string gprint(logger::LogLevel const level, std::string message); 
        void print(logger::LogLevel const level, std::string message);
    
};

logger::logger()
{
}

logger::~logger()
{
}

void logger::print(logger::LogLevel const level, std::string message)
{
    fmt::print(fmt::format("{}", message));
}

#endif // LOGGER_H
