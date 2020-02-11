#include "Scene.h"
Scene::Scene(Engine* engine) {
	_gameObjects = std::vector<GameObject*>(0);
	_camera = new Camera(engine);

	_sunlightDir = glm::vec3(0.0f);
	_dirlightShader = glGetUniformLocation(*engine->getProgramID(), "directionalLightrot");
}
Scene::~Scene() {

}
void Scene::addGameObj(GameObject* obj) {
	_gameObjects.push_back(obj);
}

Camera* Scene::getCamera() {
	return _camera;
}

glm::vec3 Scene::getDirlightrot()
{
	return _sunlightDir;
}

GLuint Scene::getDirlightShader()
{
	return _dirlightShader;
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
