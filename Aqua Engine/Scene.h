#pragma once
#include "dependencies.h"
#include "GameObject.h"
#include "Camera.h"
class GameObject;

class Scene
{
public:
	Scene(Engine* engine);
	~Scene();

	void addGameObj(GameObject* obj);
	Camera* getCamera();
	glm::vec3 getDirlightrot();
	GLuint getDirlightShader();
	void updateScene();
private:
	std::vector<GameObject*> _gameObjects;
	Camera* _camera;

	glm::vec3 _sunlightDir;
	GLuint _dirlightShader;
};