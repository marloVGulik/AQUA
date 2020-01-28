#include "GameObject.h"

GameObject::GameObject(std::string path) {
	std::vector<unsigned int> vertexIn, UVIn, normalIn;
	std::vector<glm::vec3> tempVert;
	std::vector<glm::vec2> tempUV;
	std::vector<glm::vec3> tempNormals;

	FILE* objFile = fopen(path.c_str(), "r");
	if (objFile == NULL) {
		std::cout << "Error opening file!\n";
		return;
	}
	while (1) {
		char lineHeader[128];
		int res = fscanf(objFile, "%s", lineHeader);
		if (res == EOF) {
			break;
		}
	}


	_vertexBuffer = new GLuint;
	glGenBuffers(1, _vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices.data()) * vertices.size(), static_cast<void*>(vertices.data()), GL_STATIC_DRAW);

	_UVBuffer = new GLuint;
	glGenBuffers(1, _UVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_UVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(UV.data()) * UV.size(), static_cast<void*>(UV.data()), GL_STATIC_DRAW);

	_vertSize = (int)vertices.size() / 3;

	_texture = new GLuint;
	*_texture = loadBMP(path);
	_usedEngine = engine;
	_textureID = new GLuint;
	*_textureID = glGetUniformLocation(*_usedEngine->getProgramID(), "textureSampler");

	_loc = glm::vec3(0.0f);
	_rot = glm::vec3(0.0f);
	_scale = glm::vec3(1.0f);
	_modelMatrix = glm::mat4(1.0f);

	_view = _usedEngine->getView();
	_projection = _usedEngine->getProjection();

	_MVP = glm::mat4(*_projection * *_view * _modelMatrix);
}
GameObject::~GameObject() {

}
void GameObject::objectPollEvents() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, *_texture);
	glUniform1i(*_textureID, 0);

	_MVP = glm::mat4(*_projection * *_view * _modelMatrix);
	glUniformMatrix4fv(_usedEngine->getMatrixID(), 1, GL_FALSE, &_MVP[0][0]);

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

	glDrawArrays(GL_TRIANGLES, 0, _vertSize);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}