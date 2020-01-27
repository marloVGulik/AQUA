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

	float* getDTpointer();

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

	float* _deltaTime;
	double* _currentTime;
	double* _oldTime;

	bool stopLoop = true;
};

