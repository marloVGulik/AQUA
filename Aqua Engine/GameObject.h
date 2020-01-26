#pragma once
#include "dependencies.h"
#include "Engine.h"
#include "LoadBMP.h"

class Engine;

class GameObject
{
public:
	GameObject(std::vector<GLfloat> vertices, std::vector<GLfloat> UV, std::string path, Engine* engine);
	~GameObject();

	void objectPollEvents();

private:
	int _vertSize;
	GLuint* _vertexBuffer;
	GLuint* _UVBuffer;

	GLuint* _texture;
	GLuint* _textureID;

	Engine* _usedEngine;
};