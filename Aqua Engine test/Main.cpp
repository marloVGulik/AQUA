#include "Main.h"

int main() {

	Engine* engine = new Engine("Official aqua engine test!");
	engine->loadShaders("Data/Shaders/shader.vert", "Data/Shaders/shader.frag");
	Scene* scene = engine->getScene();
	Console* console = engine->getConsole();

	console->log("Creating object");
	GameObject* obj = new GameObject();
	scene->addGameObj(obj);

	
	console->log("Starting main loop");
	while (engine->getWindow()->isOpen() && !glfwWindowShouldClose(engine->getWindow()->getWindow())) {
		

		engine->update();
	}
	console->log("Closed main loop");

	glfwTerminate();

	console->aqua("Stopped program succesfully with code 0!");
	return 0;
}