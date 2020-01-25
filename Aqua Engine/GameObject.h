#pragma once
#include "dependencies.h"
#include "RGB.h"
#include "objSizes.h"

class GameObject
{
public:
	GameObject(std::vector<GLfloat> vertices);
	~GameObject();

	void objectPollEvents();

private:
	std::vector<GLfloat> _vertices;
	std::vector<int> _indices;
	std::vector<float> _colors;

	int _vertSize;
	GLuint* _vertexBuffer;
};