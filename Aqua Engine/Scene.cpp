#include "Scene.h"
Scene::Scene() {
	_gameObjects = std::vector<GameObject*>(0);
}
Scene::~Scene() {

}
void Scene::addGameObj(GameObject* obj) {
	_gameObjects.push_back(obj);
}

void Scene::updateScene() {
	// UPDATE SCENE
	for (int i = 0; i < _gameObjects.size(); i++) {
		_gameObjects[i]->objectPollEvents();
	}
}
