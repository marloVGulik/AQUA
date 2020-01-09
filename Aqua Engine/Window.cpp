#include "Window.h"

Window::Window() {
	_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(_monitor);
	
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	_window = glfwCreateWindow(mode->width, mode->height, _title.c_str(), _monitor, NULL);
	if (_window == nullptr) {
		std::cerr << "ERROR: window not created!" << std::endl;
	}
	else {
		_open = true;
	}
}
Window::~Window() {
	if (_window != nullptr) {
		glfwDestroyWindow(_window);
	}
}

bool Window::pollEvents() {
	if (glfwWindowShouldClose(_window)) {
		_open = false;
	}
	return true;
}
bool Window::isOpen() {
	return _open;
}
void Window::close() {
	glfwDestroyWindow(_window);
	_window = nullptr;
}