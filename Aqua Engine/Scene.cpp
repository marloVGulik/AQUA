#include "Scene.h"
Scene::Scene(Engine* engine) {
	_gameObjects = std::vector<GameObject*>(0);
	_camera = new Camera(engine);
}
Scene::~Scene() {

}
void Scene::addGameObj(GameObject* obj) {
	_gameObjects.push_back(obj);
}

Camera* Scene::getCamera() {
	return _camera;
}

void Scene::updateScene() {
	// UPDATE SCENE
	if (_camera != nullptr) {
		_camera->update();
	}
	for (int i = 0; i < _gameObjects.size(); i++) {
		_gameObjects[i]->objectPollEvents();
	}
}
