#pragma once
#include <string>
#include "time.h"
#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <typeinfo>
#include <iostream>
#include <stdio.h>
#include "pico/stdio.h"
#include "pico/stdlib.h"


//	---------------------- NAMES ----------------------
#define ENTER "Entering"
#define LEAVE "Leaving"
#define MESSAGE "Message"
#define WARNING "Warning"

//	---------------------- COLORS ----------------------
#define RED_COLOR "\033[38;5;196m"
#define GREEN_COLOR "\033[38;5;46m"
#define YELLOW_COLOR "\033[38;5;226m"
#define BLUE_COLOR "\033[38;5;21m"
#define MAGENTA_COLOR "\033[38;5;206m"
#define CYAN_COLOR "\033[38;5;51m"
#define WHITE_COLOR "\033[38;5;15m"
#define RESET_COLOR "\033[0m"
#define BOLD_UNDERLINE "\x1b[37;1;4m"
#define LIGHT_BLUE_COLOR "\033[38;5;39m"

//	---------------------- FUNCTIONALITIES COLORS ----------------------
#define FONT_STYLE_FILE BOLD_UNDERLINE
#define COLOR_VAR LIGHT_BLUE_COLOR
#define COLOR_INFORMATION YELLOW_COLOR
#define COLOR_STRING "\x1b[38;5;208m"
#define COLOR_LITERAL_TYPE "\x1b[94m"
#define COLOR_USER_DEFINED_TYPE "\x1b[32;2;255;214;143m"
#define COLOR_FUNC "\x1b[38;2;220;220;170m"
#define COLOR_MESSAGE "\x1b[38;5;154m"
#define COLOR_WARNING RED_COLOR
#define COLOR_CLASS COLOR_USER_DEFINED_TYPE

//	---------------------- SYMBOLS ----------------------
#define LEFT_ARROW "\u2190"
#define UP_ARROW "\u2191"
#define RIGHT_ARROW "\u2192"
#define DOWN_ARROW "\u2193"
#define LEFT_RIGHT_ARROW "\u2194"
#define UP_DOWN_ARROW "\u2195"

//	---------------------- FUNCTION MACROS ----------------------
#define LOG_START_PROGRAM() (Logger::StartProgram())
#define LOG_EXIT_PROGRAM() (Logger::ExitProgram())
#define LOG_INITIALIZE(distance) (Logger::Initialize(distance))
#define LOG_VARIABLE(type, var) (Logger::Variable(type, #var, std::to_string(var), COLOR_LITERAL_TYPE))
#define LOG_VARIABLE_INFO(var) (Logger::VariableInfo(#var, var))
#define LOG_VARIABLE_STRING(var) (Logger::Variable("string", #var, var, COLOR_USER_DEFINED_TYPE))
#define LOG_ENTER() (Logger::Enter(__func__))
#define LOG_ENTER_CLASS(className, funcName) (Logger::EnterClass(className, funcName))
#define LOG_ENTER_EXT() (Logger::Enter(__func__, __FILE__, __LINE__))
#define LOG_LEAVE() (Logger::Leave(__func__))
#define LOG_LEAVE_CLASS(className, funcName) (Logger::LeaveClass(className, funcName))
#define LOG_MESSAGE(message) (Logger::Log(message))
#define LOG_MESSAGE_EXT(message) (Logger::Log(message, __func__, __FILE__, __LINE__))
#define LOG_WARNING(message) (Logger::Warning(message))
#define LOG_WARNING_EXT(message) (Logger::Warning(message, __func__, __FILE__, __LINE__))
#define LOG_PRINT_COMPILATION_INFO() (Logger::PrintCompilationInfo())
#define LOG_EMPTY_LINE() (Logger::InsertEmptyLine())


class Logger
{
public:
	struct Type
	{
		static const std::string String;
		static const std::string Int;
	};
	
private:
	static uint16_t _distance;
	static uint16_t _iterator;
	static std::string GetDistance(uint16_t additional);

public:
    static void Initialize(uint16_t distance);
	static void Log(std::string text, std::string funcName, std::string fileName, int line);
	static void Log(std::string text);
	static void Enter(std::string text);
	static void EnterClass(std::string className, std::string funcName);
	static void Enter(std::string funcName, std::string fileName, int line);
	static void Leave(std::string text);
	static void LeaveClass(std::string className, std::string funcName);
	static void Variable(std::string type, std::string name, std::string value, std::string color);
	static void Warning(std::string message, std::string funcName, std::string fileName, int line);
	static void Warning(std::string message);
	static void InsertEmptyLine();
	static void StartProgram();
	static void PrintCompilationInfo();
	static void ExitProgram();

	// Type information
	static std::string ToBit(int value);
	static void VariableInfo(std::string name, int variable);
};

