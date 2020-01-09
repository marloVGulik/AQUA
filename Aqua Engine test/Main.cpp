#include "Main.h"

int main() {
	if (!glfwInit()) {
		std::cout << "ERROR: initializing glfw failed!" << std::endl;
		return -1;
	}

	Window* window = new Window();

	while (window->isOpen()) {
		std::cout << "TESTING OWO\n";
		window->pollEvents();
	}
	window->close();
	std::cout << "Program ended!" << std::endl;

	glfwTerminate();
	return 0;
}