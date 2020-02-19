#include "Console.hpp"

Console::Console(int debugMode, std::string fileName) {
	_debugMode = debugMode;
	_outFile = new std::ofstream;
	_fileLoc = fileName;
	_outFile->open(_fileLoc);

	if (!_outFile->is_open()) {
		std::cout << "Error opening file!\n";
	}
	else { // Generate basic .html for reading purpose
		*_outFile << "<!DOCTYPE html>";
		*_outFile << "<html lang=\"en\">";
		*_outFile << "<head>";
		//*_outFile << "<link rel=\"stylesheet\" href=\"CSS\\main.css\">";
		*_outFile << "<style>body {background-color: #000000; color: #FFFFFF}button {border: 1px solid #FF0000;background-color: #000000;color: #FFFFFF;padding: 1em;width: 100px;height: 100%;margin-left: 2em}div {border: 1px solid #313131; border-radius: 1rem; box-sizing: border-box; margin:  0.5em 0;}p {padding: 1em; margin: 0;}.log {border-color: #808080; color: #808080;}.warn {border-color: #FFFF00; color: #FFFF00;}.error {border-color: #FF0000; color: #FF0000;}.aqua {border-color: #80FFFF; color: #80FFFF}.glfwError {border-color: #00FF00; color: #00FF00;}.buttonDiv{border-color: #FF0000;color: #FFFFFF;}</style>";
		*_outFile << "<meta charset=\"UTF - 8\">";
		*_outFile << "<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1.0\">";
		*_outFile << "<meta http-equiv=\"X - UA - Compatible\" content=\"ie = edge\">";
		*_outFile << "<title>Program debug</title>";
		*_outFile << "<script src='logger.js'></script>";
		*_outFile << "</head>";
		*_outFile << "<body>";
		*_outFile << "<script>generate();</script>";
	}


	*_outFile << "<div class=\"aqua\"><p>" << _getDT() << ": AQUA: Started Aqua debugger!</p></div>";
	std::cout << "\033[0;36m" << _getDT() << "AQUA: \033[0m" << "Started Aqua debugger!" << "\n\n\n";
	_outFile->close();
}
Console::~Console() {
	*_outFile << "</body>";
	_outFile->close();
	_outFile = nullptr;
}



void Console::log(std::string msg) {
	_outFile->open(_fileLoc, std::fstream::app);
	*_outFile << "<div class=\"log\"><p>" << _getDT() << ": LOG: " << msg << "</p></div>";
	std::cout << "\033[0;37m" << _getDT() << "LOG: \033[0m" << msg << "\n\n";
	_outFile->close();
}

void Console::warn(std::string msg) {
	_outFile->open(_fileLoc, std::fstream::app);
	*_outFile << "<div class=\"warn\"><p>" << _getDT() << ": WARN: " << msg << "</p></div>";
	std::cout << "\033[0;33m" << _getDT() << "WARN: \033[0m" << msg << "\n\n";
	_outFile->close();
}

void Console::error(std::string msg) {
	_outFile->open(_fileLoc, std::fstream::app);
	*_outFile << "<div class=\"error\"><p>" << _getDT() << ": ERROR: " << msg << "</p></div>";
	std::cout << "\033[0;31m" << _getDT() << "ERROR: \033[0m" << msg << "\n\n";
	_outFile->close();
}

void Console::aqua(std::string msg) {
	_outFile->open(_fileLoc, std::fstream::app);
	*_outFile << "<div class=\"aqua\"><p>" << _getDT() << ": AQUA: " << msg << "</p></div>";
	std::cout << "\033[0;36m" << _getDT() << "AQUA: \033[0m" << msg << "\n\n";
	_outFile->close();
}
void Console::err_callback(int error, const char* description) {
	_outFile->open(_fileLoc, std::fstream::app);
	*_outFile << "<div class=\"GLFW\"><p>" << _getDT() << "GLFW ERROR: " << description << "</p></div>";
	std::cout << "\033[0;31m" << _getDT() << "GLFW ERROR: \033[0m" << description << "\n\n";
	_outFile->close();
}

char* Console::_getDT() {
	time_t now = time(0);
	char* output = ctime(&now);
	return output;
}