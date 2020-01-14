#pragma once
#include <GLFW/glfw3.h>
#include "dependencies.h"

class Window
{
public:
	Window(int w, int h, std::string title, bool isFullscreen);
	~Window();

	bool pollEvents();
	bool isOpen();
	void close();

private:
	int _width = 800;
	int _height = 600;
	std::string _title = "Title not set!";
	bool _open = false;

	GLFWmonitor* _monitor = nullptr;
	GLFWwindow* _window = nullptr;
};

