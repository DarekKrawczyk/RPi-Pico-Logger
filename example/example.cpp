#include <stdio.h>
#include "pico/stdlib.h"
#include "../src/Logger.h"

// TODO:
// 1) Add all types.
// 2) Create .md file for github with explanation and example. How to use this lib and download tourial.
// 3) After that refector the code.
// 4) Create release branch.

void calcAVG()
{
    // For function to be logged, LOG_ENTER() and LOG_LEAVE() are necessary.
    LOG_ENTER();

    // Simple text to console.
    LOG_WARNING_EXT("Argument is 0!");
    LOG_MESSAGE_EXT("Setting default avg value");

    int avg = 24;
    // Printing hex, bin value of "avg" variable.
    LOG_VARIABLE_INFO(avg);

    LOG_LEAVE();
}

int main()
{
    stdio_init_all();

    // Initializing logger. Parameter is number of white space sign in logging tree. For 3 => "___" etc...
    LOG_INITIALIZE(3);

    // Placing LOG_START_PROGRAM() causes program to stop until "Enter" key is pressed.
    LOG_START_PROGRAM();

    // Display compilation information.
    LOG_PRINT_COMPILATION_INFO();

    // First enter.
    LOG_ENTER();

    int loopCounter = 0;

    // Message with additional information.
    LOG_MESSAGE_EXT("Entering while loop!");
    while (loopCounter < 1)
    {
        LOG_VARIABLE(Logger::Type::Int, loopCounter);

        LOG_MESSAGE("Hello world");
        int var = 5;
        std::string s = "ss";

        // To log variable value, LOG_VARIABLE() can be used, it requires Logger::Type to be passed.
        LOG_VARIABLE(Logger::Type::Int, var);

        // Another way to log variable is to LOG_VARIABLE_INFO(). It is used for numeric variable types.
        LOG_VARIABLE_INFO(var);

        // To log string type variable, use LOG_VARIABLE_STRING().
        LOG_VARIABLE_STRING(s);

        // Simple message.
        LOG_MESSAGE("Now enter another function");

        calcAVG();
        sleep_ms(1000);
        loopCounter++;
    }
    LOG_MESSAGE("Left while loop");
    LOG_LEAVE();

    // Exiting logging.
    LOG_EXIT_PROGRAM();
    return 0;
}