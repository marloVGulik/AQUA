#pragma once
#include "pch.h"

class EXPORT Debug {
public:
	Debug(int debugMode);
	~Debug();

	void log(std::string msg);
	void warn(std::string msg);
	void error(std::string msg);
private:
	bool _initiated = false;
	int _debugMode = 0;

	std::ofstream* _logFile = nullptr;
};