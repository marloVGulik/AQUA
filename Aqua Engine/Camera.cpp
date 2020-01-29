#include "Camera.h"

Camera::Camera(Engine* engine) {
	_speed = new float(3.0f);
	_boundObject = nullptr;
	_objPos = new glm::vec3(1.0f);
	_offset = glm::vec3(0.0f);
	_usedEngine = engine;

	_deltaTime = engine->getDTpointer();

	_hAngle = new double(0);
	_vAngle = new double(0);

	engine->getWindowSizes(&_width, &_height);

	double xpos, ypos;
	glfwGetCursorPos(engine->getWindow()->getWindow(), &xpos, &ypos);

	_sensitivity = 0.0005f;

	*_hAngle += float(_sensitivity * (_width / 2 - xpos));
	*_vAngle += float(_sensitivity * (_height / 2 - ypos));

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
			glm::vec3(0, -1, 0)
		)
	);
	_viewMatrix = _usedEngine->getView();

	_pos = glm::vec3(4, 3, 3);
}

Camera::~Camera() {
	_boundObject = nullptr;
	_usedEngine = nullptr;
}

void Camera::update() {
	//_pos.z -= 0.00001f * *_deltaTime;
	GLFWwindow* window = _usedEngine->getWindow()->getWindow();
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		_pos += _direction * *_deltaTime * *_speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		_pos -= _direction * *_deltaTime * *_speed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		_pos += _right * *_deltaTime * *_speed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		_pos -= _right * *_deltaTime * *_speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		_pos -= _up * *_deltaTime * *_speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		_pos += _up * *_deltaTime * *_speed;
	}

	double xpos, ypos;
	glfwGetCursorPos(_usedEngine->getWindow()->getWindow(), &xpos, &ypos);

	*_hAngle += float(_sensitivity * (_width / 2 - xpos));
	*_vAngle += float(_sensitivity * (_height / 2 - ypos));

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

	_usedEngine->setView(
		glm::lookAt(
			_pos,
			_pos + _direction,
			_up
		)
	);
	glfwSetCursorPos(_usedEngine->getWindow()->getWindow(), _width / 2, _height / 2);
}
