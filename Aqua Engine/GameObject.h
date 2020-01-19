#pragma once
#include "dependencies.h"
#include "RGB.h"
#include "objSizes.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void objectPollEvents();

private:
	float _vertices[10];
	float _colors[];
	int _numInputType;
};