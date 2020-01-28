#include "Camera.h"

Camera::Camera(GameObject* boundObj, glm::vec3 offset, Engine* engine) {
	_boundObject = boundObj;
	_offset = offset;
	_usedEngine = engine;

	_deltaTime = engine->getDTpointer();

	_hAngle = new double(0);
	_vAngle = new double(0);

	engine->getWindowSizes(&_width, &_height);

	double xpos, ypos;
	glfwGetCursorPos(engine->getWindow()->getWindow(), &xpos, &ypos);

	_sensitivity = 0.005f;

	*_hAngle += float(_sensitivity * _width / 2 - xpos);
	*_vAngle += float(_sensitivity * _height / 2 - ypos);

	_direction = glm::vec3(
		cos(*_vAngle) * sin(*_hAngle),
		sin(*_vAngle),
		cos(*_vAngle) * cos(*_hAngle)
	);

	_right = glm::vec3(
		sin(*_hAngle - 3.14f / 2.0f),
		0,
		cos(*_hAngle - 3.14f / 2.0f)
	);
	_up = glm::cross(_right, _direction);

	_FoV = 45.0f;
	//_objPos = new glm::vec3(boundObj);

	_usedEngine->setProjection(glm::perspective(glm::radians(_FoV), float(_width / _height), 0.1f, 100.0f));
	_projectionMatrix = _usedEngine->getProjection();
	_usedEngine->setView(
		glm::lookAt(
			glm::vec3(4, 3, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
		)
	);
	_viewMatrix = _usedEngine->getView();
}
