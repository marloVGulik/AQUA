#include "Main.h"

int main() {

	Engine* engine = new Engine("Official aqua engine test!");
	engine->loadShaders("Data/Shaders/shader.vert", "Data/Shaders/shader.frag");
	Scene* scene = engine->getScene();
	Console* console = engine->getConsole();

	Camera* cam = scene->getCamera();
	console->log("Creating object");
	//GameObject* obj = new GameObject("Data/Models/cube.obj", "Data/textures/cube.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj = new GameObject("Data/Models/ball.obj", "Data/textures/ball.bmp", glm::vec3(0.0f), engine);
	
	// testing icospheres!
	//GameObject* obj = new GameObject("Data/Models/ico.obj", "Data/textures/ico.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj = new GameObject("Data/Models/icox2.obj", "Data/textures/icox2.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj = new GameObject("Data/Models/icox4.obj", "Data/textures/icox4.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj = new GameObject("Data/Models/icox5.obj", "Data/textures/icox5.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj = new GameObject("Data/Models/icox6.obj", "Data/textures/icox6.bmp", glm::vec3(0.0f), engine); // STOP HERE! 20.000 vert

	// Cursed icospheres
	//GameObject* obj = new GameObject("Data/Models/icox5.obj", "Data/textures/icox6.bmp", engine);
	//GameObject* obj = new GameObject("Data/Models/icox5.obj", "Data/textures/icox6.bmp", engine);

	//GameObject* obj = new GameObject("Data/Models/ocean.obj", "Data/textures/icox6.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj2 = new GameObject("Data/Models/ocean.obj", "Data/textures/icox6.bmp", glm::vec3(0.0f), engine);
	//GameObject* obj3 = new GameObject("Data/Models/ocean.obj", "Data/textures/icox6.bmp", glm::vec3(0.0f), engine);
	GameObject* obj = new GameObject("Data/Models/Suzanne.obj", "Data/textures/Suzanne.bmp", glm::vec3(1.0f, 10.0f, 0.0f), engine);
	//GameObject* obj2 = new GameObject("Data/Models/icox6.obj", "Data/textures/icox6.bmp", glm::vec3(0.0f, 0.0f, 3.0f), engine);
	scene->addGameObj(obj);
	//scene->addGameObj(obj2);
	//scene->addGameObj(obj3);
	
	bool testMaps = false;
	if (testMaps) {
		for (unsigned short i = 0; i < 100; i++) {
			scene->addGameObj(obj);
		}
	}

	
	console->log("Starting main loop");
	while (engine->getWindow()->isOpen() && !glfwWindowShouldClose(engine->getWindow()->getWindow())) {
		if (!engine->update()) {
			break;
		}
	}
	console->log("Closed main loop");

	glfwTerminate();

	console->aqua("Stopped program succesfully with code 0!");
	return 0;
}