
#include <iostream>

#include <player.cpp>
#include <logger.h>

static logger log;

int main()
{
      log.print(log.INFO_LEVEL, "kokot");
      
      return 0;
}
