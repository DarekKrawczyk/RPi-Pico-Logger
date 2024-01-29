#include "Logger.h"

const std::string Logger::Type::String = "String";
const std::string Logger::Type::Int = "int";

uint16_t Logger::_distance;
uint16_t Logger::_iterator;


std::string Logger::GetDistance(uint16_t additional = 0)
{
	std::string tmp = "";
	for (int i = 0; i < (_iterator + additional); i++) {
		for (int j = 0; j < _distance; j++) {
			tmp += " ";
		}
	}
	return tmp;
}

void Logger::Initialize(uint16_t distance)
{
	_distance = distance;
	_iterator = 0;
}

void Logger::Log(std::string text, std::string funcName, std::string fileName, int line)
{
	std::string temp = GetDistance();

	std::string file = "";
    size_t pos = fileName.find_last_of("\\/");
    
    // Check if a directory separator is found
    if (pos != std::string::npos) {
        // Extract the substring from the last directory separator to the end
        file = fileName.substr(pos + 1);
    } else {
        // If no directory separator is found, use the whole fileName
        file = fileName;
    }

	printf((temp + "(" + COLOR_MESSAGE + MESSAGE + RESET_COLOR + " in " + FONT_STYLE_FILE + file + RESET_COLOR + " at " + FONT_STYLE_FILE + std::to_string(line) + RESET_COLOR + " line" + ") : " + text + "\n").c_str());
}

void Logger::Log(std::string text)
{
	std::string temp = GetDistance();
	printf((temp + "(" + COLOR_MESSAGE + MESSAGE + RESET_COLOR + ") : " + text + "\n").c_str());
}

void Logger::EnterClass(std::string className, std::string funcName)
{
	std::string tmp = GetDistance();
	std::string distance = GetDistance(1);

	// (ENTERING): 
	printf((tmp + "(" + COLOR_FUNC + ENTER + RESET_COLOR + "): ").c_str());

	// Class name
	printf((COLOR_CLASS + className + RESET_COLOR + "::").c_str());

	// Function name
	printf((COLOR_FUNC + funcName + "()" + RESET_COLOR + "\n").c_str());

	// Down arrow
	printf((distance + DOWN_ARROW + '\n').c_str());

	_iterator++;
}

void Logger::Enter(std::string text)
{
	std::string tmp = GetDistance();
	std::string distance = GetDistance(1);

	// (ENTERING): 
	printf((tmp + "(" + COLOR_FUNC + ENTER + RESET_COLOR + "): ").c_str());

	// Function name
	printf((text + "()\n").c_str());

	// Down arrow
	printf((distance + DOWN_ARROW + '\n').c_str());

	_iterator++;
}

void Logger::Leave(std::string text)
{
	std::string tmp = GetDistance();

	// Down arrow
	printf((tmp + DOWN_ARROW + '\n').c_str());

	_iterator--;
	tmp = GetDistance();

	// (LEAVING): 
	printf((tmp + "(" + COLOR_FUNC + LEAVE + RESET_COLOR + "): ").c_str());

	// Function name
	printf((text + "()\n").c_str());
}

void Logger::LeaveClass(std::string className, std::string funcName)
{
	std::string tmp = GetDistance();

	// Down arrow
	printf((tmp + DOWN_ARROW + '\n').c_str());

	_iterator--;
	tmp = GetDistance();

	// (LEAVING): 
	printf((tmp + "(" + COLOR_FUNC + LEAVE + RESET_COLOR + "): ").c_str());

	// Class name
	printf((COLOR_CLASS + className + RESET_COLOR + "::").c_str());

	// Function name
	printf((COLOR_FUNC + funcName + "()" + RESET_COLOR + "\n").c_str());
}

void Logger::Variable(std::string type, std::string name, std::string value, std::string color)
{
	std::string temp = GetDistance();
	if (type == "string") {
		temp += ("|" + color + type + RESET_COLOR + " " + name + " = " + COLOR_STRING + "\"" + value + "\"" + RESET_COLOR + "\n");
	}
	else {
		temp += ("|" + color + type + RESET_COLOR + " " + name + " = " + value + "\n");
	}
	printf(temp.c_str());
}

void Logger::Warning(std::string message, std::string funcName, std::string fileName, int line)
{
	std::string temp = GetDistance();

	std::string file = "";
    size_t pos = fileName.find_last_of("\\/");
    
    // Check if a directory separator is found
    if (pos != std::string::npos) {
        // Extract the substring from the last directory separator to the end
        file = fileName.substr(pos + 1);
    } else {
        // If no directory separator is found, use the whole fileName
        file = fileName;
    }

	printf((temp + "(" + COLOR_WARNING + WARNING + RESET_COLOR + " in " + FONT_STYLE_FILE + file + RESET_COLOR + " at " + FONT_STYLE_FILE + std::to_string(line) + RESET_COLOR + " line" + ") : " + message + "\n").c_str());
}

void Logger::Warning(std::string message)
{
	std::string temp = GetDistance();
	printf((temp + "(" + COLOR_WARNING + WARNING + RESET_COLOR + ") : " + message + "\n").c_str());
}

std::string Logger::ToBit(int value)
{
	std::string result = COLOR_LITERAL_TYPE "0b(" RESET_COLOR;
	int size = sizeof(value) * 8;

	for (int i = size - 1; i >= 0; --i) {
		int bit = (value >> i) & 1;
		result += std::to_string(bit);
		if(i%8==0 && (i!=0)) result+= " ";
	}
	result += COLOR_LITERAL_TYPE ")" RESET_COLOR;
	return result.c_str();
}

void Logger::VariableInfo(std::string name, int variable)
{
	// TODO
	std::string temp = GetDistance();
	//printf((temp + "(" + COLOR_MESSAGE + "Variable info" + RESET_COLOR + ") " + name + " = " + std::to_string(variable) +
	//	"; 0b" + ToBit(variable) + "; 0x%X\n", variable));
}

void Logger::Enter(std::string funcName, std::string fileName, int line)
{
	std::string tmp = GetDistance();
	std::string distance = GetDistance(1);

	// (ENTERING): 
	printf((tmp + "(" + COLOR_FUNC + ENTER + RESET_COLOR + "): ").c_str());

	std::string file = "";
    size_t pos = fileName.find_last_of("\\/");
    
    // Check if a directory separator is found
    if (pos != std::string::npos) {
        // Extract the substring from the last directory separator to the end
        file = fileName.substr(pos + 1);
    } else {
        // If no directory separator is found, use the whole fileName
        file = fileName;
    }

	std::string bug_workaround = "";
	// Function name
	printf((bug_workaround + "Function: " + FONT_STYLE_FILE + funcName + "()" + RESET_COLOR + " File: " + FONT_STYLE_FILE + file + RESET_COLOR + " Line: " + FONT_STYLE_FILE + std::to_string(line) + RESET_COLOR + "\n").c_str());

	// Down arrow
	printf((distance + DOWN_ARROW + '\n').c_str());

	_iterator++;
}