#include "GameObject.h"

GameObject::GameObject(std::string path, std::string imgPath, glm::vec3 location, Engine* engine) {
	_texture = new GLuint;
	_textureID = new GLuint;
	_usedEngine = engine;

	_scene = engine->getScene();

	std::vector<GLfloat> outVert;
	std::vector<GLfloat> outUV;
	std::vector<GLfloat> outNormals;

	_vertSize = loadOBJ(path, outVert, outUV, outNormals);
	if (_vertSize == 0) {
		return;
	}
	//_vertSize = outVert.size();
	//std::cout << _vertSize << "\n";

	*_texture = loadBMP(imgPath);
	*_textureID = glGetUniformLocation(*_usedEngine->getProgramID(), "textureSampler");
	_modelMatrixID = glGetUniformLocation(*_usedEngine->getProgramID(), "M");
	_viewMatrixID = glGetUniformLocation(*_usedEngine->getProgramID(), "V");

	_location = location;
	_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	_scale = glm::vec3(1.0f);
	_posToMat4();

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;

	//_transformedVector = _myTransformMatrix * _myTransfromVector;

	_view = glm::mat4(_usedEngine->getView());
	_projection = glm::mat4(_usedEngine->getProjection());

	_MVP = _projection * _view * _modelMatrix;

	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR?\n";
	}


	_vertexBuffer = new GLuint;
	glGenBuffers(1, _vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outVert.data()[0]) * outVert.size(), outVert.data(), GL_STATIC_DRAW);

	/*_vertexIndexBuffer = new GLuint;
	glGenBuffers(1, _vertexIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_vertexIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_vertexIndices.data()[0])* _vertexIndices.size(), _vertexIndices.data(), GL_STATIC_DRAW);*/

	_UVBuffer = new GLuint;
	glGenBuffers(1, _UVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_UVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outUV.data()[0]) * outUV.size(), outUV.data(), GL_STATIC_DRAW);

	_normalBuffer = new GLuint;
	glGenBuffers(1, _normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outNormals.data()[0]) * outNormals.size(), outNormals.data(), GL_STATIC_DRAW);

}
GameObject::~GameObject() {
	glDeleteBuffers(1, _vertexBuffer);
	glDeleteBuffers(1, _UVBuffer);
	glDeleteBuffers(1, _normalBuffer);
	glDeleteTextures(1, _texture);
}
void GameObject::objectPollEvents() {

	//_location.x += 1.0f * *_usedEngine->getDTpointer();

	_posToMat4();
	_view = _usedEngine->getView();
	_projection = _usedEngine->getProjection();

	_MVP = _projection * _view * _modelMatrix;

	glUniformMatrix4fv(*_usedEngine->getMatrixID(), 1, GL_FALSE, &_MVP[0][0]);
	glUniformMatrix4fv(_viewMatrixID, 1, GL_FALSE, &_view[0][0]);
	glUniformMatrix4fv(_modelMatrixID, 1, GL_FALSE, &_modelMatrix[0][0]);
	glUniform3f(_scene->getDirlightShader(), 1, GL_FALSE, _scene->getDirlightrot()[0]);


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, *_texture);
	glUniform1i(*_textureID, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, *_UVBuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, *_normalBuffer);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, _vertSize);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_vertexIndexBuffer); // Indexing doesn't work :(
	/*glDrawElements(
		GL_TRIANGLES,
		_vertSize,
		GL_UNSIGNED_SHORT,
		(void*)0
	);*/

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void GameObject::_posToMat4() {
	_translationMatrix = glm::translate(glm::mat4(1.0f), _location);
	_rotationMatrix = glm::rotate(glm::mat4(1.0f), 360.0f, _rotation);
	_scalingMatrix = glm::scale(glm::mat4(1.0f), _scale);

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;
}
