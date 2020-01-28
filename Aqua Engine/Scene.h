#pragma once
#include "dependencies.h"
#include "GameObject.h"
#include "Camera.h"
class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

	void addGameObj(GameObject* obj);
	void setCamera(Camera* cam);
	void updateScene();
private:
	std::vector<GameObject*> _gameObjects;
	Camera* _camera;
};