#include <stdio.h>
#include "pico/stdlib.h"
#include <iostream>
#include "src/Logger.h"

int main()
{
    stdio_init_all();
    LOG_INITIALIZE(3);
    LOG_ENTER();

    while(true){
        printf("%s\n", Logger::ToBit(5).c_str());
        LOG_MESSAGE("Hello world");
        LOG_ENTER();
        LOG_MESSAGE("Hello world");
        LOG_WARNING("Cos jest nie tak!");
        LOG_LEAVE();
        LOG_ENTER();
        int var = 5;
        std::string s = "ss";
        LOG_VARIABLE(Logger::Type::Int, var);
        LOG_VARIABLE_STRING(s);
        LOG_MESSAGE("Now enter another function");
        LOG_ENTER_EXT();
        LOG_WARNING_EXT("Cos jest nie tak!");
        LOG_MESSAGE_EXT("Just got here!");
        LOG_LEAVE();
        LOG_LEAVE();
        sleep_ms(1000);
    }
    LOG_LEAVE();
}