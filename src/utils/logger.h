// Last modified: 2021/08/21 21:00:00
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>

class logger
{
public:
    logger();
    ~logger();
    const char* gprint(const char* message); 
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
