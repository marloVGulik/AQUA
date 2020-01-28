#pragma once
#include "dependencies.h"
#include "Engine.h"
#include "LoadTexture.h"

class Engine;

class GameObject
{
public:
	GameObject(std::string path, std::string imgPath, Engine* engine);
	~GameObject();

	void objectPollEvents();

private:
	int _vertSize;
	GLuint* _vertexBuffer;
	GLuint* _UVBuffer;

	GLuint* _texture;
	GLuint* _textureID;

	glm::vec3 _loc;
	glm::vec3 _rot;
	glm::vec3 _scale;

	glm::mat4* _view;
	glm::mat4* _projection;
	glm::mat4 _modelMatrix;

	glm::mat4 _MVP;

	Engine* _usedEngine;
};