#pragma once
#include "dependencies.h"
#include "Aqua.h";

class Engine
{
public:
	Engine(std::string title);
	~Engine();

	Window* getWindow();
	Console* getConsole();
	Scene* getScene();
	void loadShaders(std::string pathV, std::string pathF);

	void update();

private:
	Console* _console;
	Window* _window;
	Scene* _scene;

	GLuint _programID;

	bool stopLoop = true;
};

