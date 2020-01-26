#pragma once
#include "dependencies.h"
#include "Aqua.h"
class Scene;

class Engine
{
public:
	Engine(std::string title);
	~Engine();

	Window* getWindow();
	Console* getConsole();
	Scene* getScene();
	GLuint* getProgramID();
	void loadShaders(std::string pathV, std::string pathF);

	void update();

private:
	Console* _console;
	Window* _window;
	Scene* _scene;

	GLuint* _VAID;

	GLuint _programID;
	GLuint _matrixID;
	glm::mat4 _projection;
	glm::mat4 _view;
	glm::mat4 _model;

	glm::mat4 _MVP;

	bool stopLoop = true;
};

