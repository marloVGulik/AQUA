#pragma once
#include "dependencies.h"
#include "GameObject.h"
class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

	void addGameObj(GameObject* obj);
	void updateScene();
private:
	std::vector<GameObject*> _gameObjects;
};