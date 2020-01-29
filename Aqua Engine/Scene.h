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
	void updateScene();
private:
	std::vector<GameObject*> _gameObjects;
	Camera* _camera;
};