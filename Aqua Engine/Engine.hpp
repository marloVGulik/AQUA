#pragma once
#include "dependencies.hpp"
#include "Aqua.hpp"
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
	GLuint* getMatrixID();

	glm::mat4 getProjection();
	void setProjection(glm::mat4 newView);
	glm::mat4 getView();
	void setView(glm::mat4 newView);
	
	void loadShaders(std::string pathV, std::string pathF);

	float* getDTpointer();
	void getWindowSizes(int* width, int* height);

	void update();

private:
	Console* _console;
	Window* _window;
	int* _width;
	int* _height;
	Scene* _scene;
	Camera* _camera;

	GLuint* _VAID;

	GLuint _programID;
	GLuint _matrixID;
	glm::mat4 _projection;
	glm::mat4 _view;

	float* _deltaTime;
	double* _currentTime;
	double* _oldTime;

	bool stopLoop = true;
};

