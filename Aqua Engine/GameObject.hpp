#pragma once
#include "dependencies.hpp"
#include "Engine.hpp"
#include "LoadTexture.hpp"
#include "indexer.hpp"
#include "OBJloader.hpp"


class Engine;

class GameObject
{
public:
	GameObject(std::string path, std::string imgPath, glm::vec3 location, Engine* engine);
	~GameObject();

	void objectPollEvents();

private:
	int _vertSize;
	GLuint* _vertexBuffer;
	GLuint* _vertexIndexBuffer;
	std::vector<unsigned short> _vertexIndices;
	GLuint* _UVBuffer;
	GLuint* _normalBuffer;

	GLuint* _texture;
	GLuint* _textureID;

	glm::vec3 _location;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	glm::mat4 _translationMatrix;
	glm::mat4 _rotationMatrix;
	glm::mat4 _scalingMatrix;

	glm::mat4 _view;
	glm::mat4 _projection;
	glm::mat4 _modelMatrix;

	GLuint _viewMatrixID;
	GLuint _modelMatrixID;

	glm::mat4 _MVP;

	Engine* _usedEngine;
	Scene* _scene;

	void _posToMat4();
};