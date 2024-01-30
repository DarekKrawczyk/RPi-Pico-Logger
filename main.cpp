#include <stdio.h>
#include "pico/stdlib.h"
#include <iostream>
#include "src/Logger.h"

void calcAVG(){
    LOG_ENTER();

    LOG_WARNING_EXT("Argument is 0!");
    LOG_MESSAGE_EXT("Setting default avg value");

    int avg = 24;
    Logger::VariableInfo("avg", avg);

    LOG_LEAVE();
}

int main()
{
    stdio_init_all();
    LOG_INITIALIZE(3);
    LOG_ENTER();

    while(true){
        LOG_MESSAGE("Hello world");
        int var = 5;
        std::string s = "ss";
        LOG_VARIABLE(Logger::Type::Int, var);
        Logger::VariableInfo("var", var);
        LOG_VARIABLE_STRING(s);
        LOG_MESSAGE("Now enter another function");
        calcAVG();
        sleep_ms(1000);
    }
    LOG_LEAVE();
}