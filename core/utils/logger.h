/*
#pragma once

#ifndef LOGGER_H
#define LOGGER_H

namespace logger

#include <iostream>
#include <fmt/core.h>

class logger
{
    public:
        enum LogLevel 
        {
            INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL, FATAL_LEVEL, DEBUG_LEVEL,
        }; 
        ~logger();
        logger();
        
        //utils
        std::string to_string(auto tp);
        auto as_local(std::chrono::system_clock::time_point const tp);

        std::string gprint(logger::LogLevel const level, std::string_view message);
        std::string gprint(logger::LogLevel const level, std::string message); 
        
        void print(logger::LogLevel const level, std::string message);
        void print(logger::LogLevel const level, std::string_view message);
};

logger::logger()
{
}

logger::~logger()
{
}

#endif
*/