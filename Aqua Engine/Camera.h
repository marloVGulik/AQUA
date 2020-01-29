#pragma once
#include "dependencies.h"
#include "Engine.h"
#include "GameObject.h"

class Camera {
public:
	Camera(Engine* engine);
	~Camera();
	void update();



private:
	glm::vec3 _pos;
	glm::vec3 _offset;

	double* _hAngle;
	double* _vAngle;

	int _width;
	int _height;

	float* _speed;

	glm::vec3 _direction;
	glm::vec3 _right;
	glm::vec3 _up;

	glm::mat4* _projectionMatrix;
	glm::mat4* _viewMatrix;

	Engine* _usedEngine;
	float* _deltaTime;
	GameObject* _boundObject;
	glm::vec3* _objPos;

	// Settings
	float _sensitivity;
	float _FoV;
};

