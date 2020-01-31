#include "GameObject.h"

GameObject::GameObject(std::string path, std::string imgPath, Engine* engine) {
	std::vector<unsigned int> UVIn, normalIn;
	std::vector<glm::vec3> tempVert;
	std::vector<glm::vec2> tempUV;
	std::vector<glm::vec3> tempNormals;

	_texture = new GLuint;
	_textureID = new GLuint;
	_usedEngine = engine;

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
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(objFile, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			//std::cout << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
			tempVert.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 UV;
			fscanf(objFile, "%f %f\n", &UV.x, &UV.y);
			//std::cout << UV.x << " " << UV.y << "\n";
			tempUV.push_back(UV);
		}
		else if (strcmp(lineHeader, "vn") == 0) { // Not used
			glm::vec3 normal;
			fscanf(objFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			//std::cout << normal.x << " " << normal.y << " " << normal.z << "\n";
			tempNormals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(objFile, "%u/%u/%u %u/%u/%u %u/%u/%u\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				std::cout << "FILE ERROR!\n";
				return;
			}
			//std::cout << vertexIndex[0] << "/" << uvIndex[0] << "/" << normalIndex[0] << " ";
			//std::cout << vertexIndex[0] << " " << vertexIndex[1] << " " << vertexIndex[2] << "\n";
			if (vertexIndex[0] == 0 || vertexIndex[1] == 0 || vertexIndex[2] == 0) {
				std::cout << "reading error! " << vertexIndex[0] << "/" << vertexIndex[1] << "/" << vertexIndex[2] << "\n";
			}
			_vertexIndices.push_back(vertexIndex[0] - 1);
			_vertexIndices.push_back(vertexIndex[1] - 1);
			_vertexIndices.push_back(vertexIndex[2] - 1);

			//std::cout << vertexIndex[1] << "/" << uvIndex[1] << "/" << normalIndex[1] << " ";
			UVIn.push_back(uvIndex[0] - 1);
			UVIn.push_back(uvIndex[1] - 1);
			UVIn.push_back(uvIndex[2] - 1);

			//std::cout << vertexIndex[2] << "/" << uvIndex[2] << "/" << normalIndex[2] << "\n";
			normalIn.push_back(normalIndex[0]);
			normalIn.push_back(normalIndex[1]);
			normalIn.push_back(normalIndex[2]);
		}
		else {
			//std::cout << "test\n";
		}
	}
	fclose(objFile);
	
	for (unsigned int i = 0; i < _vertexIndices.size(); i++) {
		if (_vertexIndices[i] == -1) {
			std::cout << "ERROR AT " << i << "\n";
		}
	}

	//std::cout << tempVert.size() << "\n";
	//std::cout << tempUV.size() << "\n";
	std::vector<GLfloat> outVert;
	std::vector<GLfloat> outUV;
	for (unsigned int i = 0; i < _vertexIndices.size(); i++) {
		if (_vertexIndices[i] == -1) {
			std::cout << "ERROR AT " << i << "\n";
		}
		glm::vec3 vertex = tempVert[_vertexIndices[i]];
		outVert.push_back(vertex.x);
		outVert.push_back(vertex.y);
		outVert.push_back(vertex.z);
	}
	/*for (unsigned int i = 0; i < tempVert.size(); i++) {
		outVert.push_back(tempVert[i].x);
		outVert.push_back(tempVert[i].y);
		outVert.push_back(tempVert[i].z);
	}*/
	for (unsigned int i = 0; i < UVIn.size(); i++) {
		glm::vec2 UV = tempUV[UVIn[i]];
		outUV.push_back(UV.x);
		outUV.push_back(UV.y);
	}
	//std::cout << "\n";
	/*for (unsigned int i = 0; i < outVert.size(); i++) {
		std::cout << outVert[i].x << ", " << outVert[i].y << ", " << outVert[i].z << "\n";
	}*/

	_vertSize = _vertexIndices.size();
	//_vertSize = outVert.size();
	//std::cout << _vertSize << "\n";

	*_texture = loadBMP(imgPath);
	*_textureID = glGetUniformLocation(*_usedEngine->getProgramID(), "textureSampler");

	_location = glm::vec3(0.0f);
	_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	_scale = glm::vec3(1.0f);
	_posToMat4();

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;

	//_transformedVector = _myTransformMatrix * _myTransfromVector;

	_view = new glm::mat4(_usedEngine->getView());
	_projection = new glm::mat4(_usedEngine->getProjection());

	_MVP = *_projection * *_view * _modelMatrix;

	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR?\n";
	}

	_vertexBuffer = new GLuint;
	glGenBuffers(1, _vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(tempVert.data()) * tempVert.size(), static_cast<void*>(tempVert.data()), GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outVert.data()[0]) * outVert.size(), outVert.data(), GL_STATIC_DRAW);

	_UVBuffer = new GLuint;
	glGenBuffers(1, _UVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_UVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outUV.data()[0]) * outUV.size(), outUV.data(), GL_STATIC_DRAW);

	//_vertexIndexBuffer = new GLuint;
	//glGenBuffers(1, _vertexIndexBuffer);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_vertexIndexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_vertexIndices.data())* _vertexIndices.size(), static_cast<void*>(_vertexIndices.data()), GL_STATIC_DRAW);

}
GameObject::~GameObject() {

}
void GameObject::objectPollEvents() {

	//_location.x += 1.0f * *_usedEngine->getDTpointer();

	_posToMat4();
	_view = &_usedEngine->getView();
	_projection = &_usedEngine->getProjection();

	_MVP = *_projection * *_view * _modelMatrix;
	glUniformMatrix4fv(*_usedEngine->getMatrixID(), 1, GL_FALSE, &_MVP[0][0]);


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
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, _vertSize);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_vertexIndexBuffer); // Indexing doesn't work :(
	//glDrawElements(
	//	GL_TRIANGLES,
	//	_vertSize,
	//	GL_UNSIGNED_SHORT,
	//	(void*)0
	//);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void GameObject::_posToMat4() {
	_translationMatrix = glm::translate(glm::mat4(1.0f), _location);
	_rotationMatrix = glm::rotate(glm::mat4(1.0f), 360.0f, _rotation);
	_scalingMatrix = glm::scale(glm::mat4(1.0f), _scale);

	_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;
}
