#include "Main.h"

int main() {
	if (!glfwInit()) {
		std::cout << "ERROR: initializing glfw failed!" << std::endl;
		return -1;
	}

	//Window* window = new Window();
	Console* console = new Console(0, "logs/log.html");
	console->log("test");
	console->warn("test");
	console->error("test");

	std::ofstream randomFile;
	randomFile.open("file.txt");
	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 1000000; i++) {
			randomFile << "The floor here is made out of floor\n";
		}
	}
	randomFile.close();
	console->error("Test 2");



	/*while (window->isOpen()) {
		std::cout << "TESTING OWO\n";
		window->pollEvents();
	}*/
	//window->close();
	std::cout << "Program ended!" << std::endl;

	glfwTerminate();
	return 0;
}