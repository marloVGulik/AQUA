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

private:
	int _debugMode = 0;
	std::ofstream* _outFile = nullptr;

	char* _getDT();
};

