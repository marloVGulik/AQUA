#include "GameObject.h"
GameObject::GameObject(std::vector<GLfloat> vertices) {
	_vertices = vertices;
	_vertexBuffer = new GLuint;
	glGenBuffers(1, _vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), static_cast<void*>(_vertices.data()), GL_STATIC_DRAW);

	_vertSize = _vertices.size() / 3;
	std::cout << _vertSize << "\n";
}
GameObject::~GameObject() {

}
void GameObject::objectPollEvents() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glVertexAttribPointer(
		0,
		_vertSize,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}