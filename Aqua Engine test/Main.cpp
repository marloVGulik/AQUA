#include "Main.h"

int main() {

	Engine* engine = new Engine("Official aqua engine test!");
	engine->loadShaders("Shaders/shader.vert", "Shaders/shader.frag");
	Scene* scene = engine->getScene();
	Console* console = engine->getConsole();

	console->log("Creating object");
	std::vector<GLfloat> vert = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};
	GameObject* obj = new GameObject(vert);
	scene->addGameObj(obj);

	console->log("Starting main loop");
	while (engine->getWindow()->isOpen() && !glfwWindowShouldClose(engine->getWindow()->getWindow())) {
		engine->update();
	}

	glfwTerminate();
	return 0;
}