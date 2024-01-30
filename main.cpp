#include <stdio.h>
#include "pico/stdlib.h"
#include "src/Logger.h"

void calcAVG(){
    LOG_ENTER();

    LOG_WARNING_EXT("Argument is 0!");
    LOG_MESSAGE_EXT("Setting default avg value");

    int avg = 24;
    LOG_VARIABLE_INFO(avg);

    LOG_LEAVE();
}

int main()
{
    stdio_init_all();
    
    LOG_INITIALIZE(3);
    LOG_START_PROGRAM();
    LOG_PRINT_COMPILATION_INFO();
    
    LOG_ENTER();

    int loopCounter = 0;
    LOG_MESSAGE_EXT("Entering while loop!");
    while(loopCounter < 3){
        LOG_MESSAGE("Hello world");
        int var = 5;
        std::string s = "ss";
        LOG_VARIABLE(Logger::Type::Int, var);
        LOG_VARIABLE_INFO(var);
        LOG_VARIABLE_STRING(s);
        LOG_MESSAGE("Now enter another function");
        calcAVG();
        sleep_ms(1000);
        loopCounter++;
    }
    LOG_MESSAGE("Left while loop");
    LOG_LEAVE();
    LOG_EXIT_PROGRAM();
    return 0;
}