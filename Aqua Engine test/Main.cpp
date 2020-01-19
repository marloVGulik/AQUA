#include "Main.h"

int main() {
	Console* console = new Console(0, "logs/log.html");
	if (!glfwInit()) {
		std::cout << "ERROR: initializing glfw failed!" << std::endl;
		return -1;
	}

	console->log("Creating window");
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	Window* window = new Window(800, 600, "Official Aqua engine test!", true);

	console->log("Starting main loop");

	while (window->isOpen() && glfwGetKey(window->getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		window->pollEvents();
	}

	if (window->getWindow() != nullptr) {
		console->log("Closing window");
		window->close();
	}

	console->log("Stopped program loop");

	glfwTerminate();
	return 0;
}