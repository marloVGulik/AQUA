#include "Main.h"

int main() {
	Console* console = new Console(0, "logs/log.html");
	if (!glfwInit()) {
		std::cout << "ERROR: initializing glfw failed!" << std::endl;
		return -1;
	}

	console->log("Creating window");
	Window* window = new Window(800, 600, "Official Aqua engine test!", false);
	console->log("Starting main loop");



	while (window->isOpen()) {
		window->pollEvents();
	}

	console->log("Stopped program loop");

	glfwTerminate();
	return 0;
}