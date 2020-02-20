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
		*_outFile << "<style>body {background-color: #000000; color: #FFFFFF}", // CSS
		*_outFile << "button {border: 1px solid #FF0000;background-color: #000000;color: #FFFFFF;padding: 1em;width: 100px;height: 100%;margin-left: 2em}";
		*_outFile << "div {border: 1px solid #313131; border-radius: 1rem; box-sizing: border-box; margin:  0.5em 0;}";
		*_outFile << "p {padding: 1em; margin: 0;}.log {border-color: #808080; color: #808080;}";
		*_outFile << ".warn {border-color: #FFFF00; color: #FFFF00;}";
		*_outFile << ".error {border-color: #FF0000; color: #FF0000;}";
		*_outFile << ".aqua {border-color: #80FFFF; color: #80FFFF}";
		*_outFile << ".glfwError {border-color: #00FF00; color: #00FF00;}";
		*_outFile << ".buttonDiv{border-color: #FF0000;color: #FFFFFF;}</style>"; // /CSS
		*_outFile << "<meta charset=\"UTF - 8\">"; // meta
		*_outFile << "<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1.0\">";
		*_outFile << "<meta http-equiv=\"X - UA - Compatible\" content=\"ie = edge\">";
		*_outFile << "<title>Program debug</title>"; // Title

		*_outFile << "<script>"; // JS
		*_outFile << "function generate() {\n";
		*_outFile << "var allButtons = document.createElement(\"div\");\n";
		*_outFile << "allButtons.className = \"buttonDiv\";\n";
		*_outFile << "var buttons = [];\n";
		*_outFile << "var buttonIDS = [\"log\", \"warn\", \"error\", \"aqua\"];\n";
		*_outFile << "for(var i = 0; i < buttonIDS.length; i++) {\n";
		*_outFile << "var tempButton = document.createElement(\"button\");\n";
		*_outFile << "tempButton.id = buttonIDS[i];\n";
		*_outFile << "tempButton.innerHTML = buttonIDS[i];\n";
		*_outFile << "tempButton.onclick = function() {\n";
		*_outFile << "var elementsOfClass = document.getElementsByClassName(this.id);\n";
		*_outFile << "var hide = true;\n";
		*_outFile << "if(elementsOfClass[0].style.display == \"none\") hide = false;\n";
		*_outFile << "for(var i = 0; i < elementsOfClass.length; i++) {\n";
		*_outFile << "if(hide) {\n";
		*_outFile << "elementsOfClass[i].style.display = \"none\";\n";
		*_outFile << "} else {\n";
		*_outFile << "elementsOfClass[i].style.display = \"block\";\n";
		*_outFile << "}\n";
		*_outFile << "}\n";
		*_outFile << "}\n";
		*_outFile << "allButtons.appendChild(tempButton);\n";
		*_outFile << "}\n";
		*_outFile << "document.body.appendChild(allButtons);\n";
		*_outFile << "}\n";
		*_outFile << "</script>"; // /JS :(

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