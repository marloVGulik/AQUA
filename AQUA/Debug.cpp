#include "pch.h"
#include "Debug.h"

Debug::Debug(int debugMode) {
	_initiated = true;
	_debugMode = debugMode;

	_logFile = new std::ofstream;
	_logFile->open("logs/AQUA.latest.LOG");
}
Debug::~Debug() {
	_initiated = false;

	_logFile->close();
	_logFile = nullptr;

	std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	if (rename("logs/AQUA.latest.LOG", "AQUA " + time) != 0) {
		std::cout << "Error renaming file!" << std::endl;
	}
}

void Debug::log(const std::string msg) {
	if (_initiated) {
		if (_debugMode < 1) {
			std::cout << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << " LOG: " << msg << "\n";
		}
		*_logFile << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << " LOG:" << msg << "\n";
	}
}