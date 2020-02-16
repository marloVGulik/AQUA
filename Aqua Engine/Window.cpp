#include "Window.hpp"

Window::Window(int w, int h, std::string title, bool isFullscreen) {
	_monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(_monitor);

	_width = w;
	_height = h;
	_title = title;

	if (isFullscreen) {
		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
		_window = glfwCreateWindow(mode->width, mode->height, _title.c_str(), _monitor, NULL);
	}
	else {
		_window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
	}
	if (_window == nullptr) {
		std::cerr << "ERROR: window not created!" << std::endl;
		_open = false;
	}
	else {
		_open = true;
		glfwMakeContextCurrent(_window);
	}
}
Window::~Window() {
	if (_window != nullptr) {
		glfwDestroyWindow(_window);
	}
}

GLFWwindow* Window::getWindow() {
	return _window;
}

bool Window::pollEvents() {
	std::cout << "OWO";
	if (_window != nullptr) {
		if (glfwWindowShouldClose(_window)) {
			_open = false;
			close();
		}

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(_window);
		glfwPollEvents();
		return true;
	}
	return false;
}
bool Window::isOpen() {
	return _open;
}
void Window::close() {
	glfwDestroyWindow(_window);
	_window = nullptr;
}