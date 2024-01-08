// Last modified: 2021/08/21 21:00:00
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>

class logger
{
public:
    logger();
    ~logger();
    void log(const char* message);
};

logger::logger()
{
}

logger::~logger()
{
}

void logger::log(const char* message)
{
      std::cout << message << std::endl;
}

#endif // LOGGER_H
