#pragma once
#include "dependencies.h"

class Console
{
public:
	Console(int debugMode);
	~Console();

private:
	int _debugMode = 0;
};

