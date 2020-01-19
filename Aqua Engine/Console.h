#pragma once
#include "dependencies.h"

class Console
{
public:
	Console(int debugMode, std::string fileName);
	~Console();

	void log(std::string msg);
	void warn(std::string msg);
	void error(std::string msg);
	void aqua(std::string msg);
	void err_callback(int error, const char* description);

private:
	int _debugMode = 0;
	std::ofstream* _outFile = nullptr;

	char* _getDT();
};

