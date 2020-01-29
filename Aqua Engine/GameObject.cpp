#include "GameObject.h"

GameObject::GameObject(std::string path, std::string imgPath, Engine* engine) {
	std::vector<unsigned int> UVIn, normalIn;
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
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(objFile, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			std::cout << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
			tempVert.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 UV;
			fscanf(objFile, "%f %f\n", &UV.x, &UV.y);
			std::cout << UV.x << " " << UV.y << "\n";
			tempUV.push_back(UV);
		}
		//else if (strcmp(lineHeader, "vn") == 0) { // Not used
		//	glm::vec3 normal;
		//	fscanf(objFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
		//	std::cout << normal.x << " " << normal.y << " " << normal.z << "\n";
		//	tempNormals.push_back(normal);
		//}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(objFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				std::cout << "FILE ERROR!\n";
				return;
			}
			std::cout << vertexIndex[0] << "/" << uvIndex[0] << "/" << normalIndex[0] << " ";
			_vertexIndices.push_back((short)vertexIndex[0]);
			_vertexIndices.push_back((short)vertexIndex[1]);
			_vertexIndices.push_back((short)vertexIndex[2]);

			std::cout << vertexIndex[1] << "/" << uvIndex[1] << "/" << normalIndex[1] << " ";
			UVIn.push_back(uvIndex[0]);
			UVIn.push_back(uvIndex[1]);
			UVIn.push_back(uvIndex[2]);

			std::cout << vertexIndex[2] << "/" << uvIndex[2] << "/" << normalIndex[2] << "\n";
			normalIn.push_back(normalIndex[0]);
			normalIn.push_back(normalIndex[1]);
			normalIn.push_back(normalIndex[2]);
		}
		else {
			std::cout << "test\n";
		}
	}

	/*std::ifstream* objFile;
	objFile->open(path);
	if (!objFile->is_open()) {
		std::cout << "ERROR OPENING FILE!\n";
		return;
	}
	char READDATA;
	while () {

	}*/


	std::cout << tempVert.size() << "\n";
	std::cout << tempUV.size() << "\n";
	std::vector<glm::vec3> outVert;
	std::vector<glm::vec2> outUV;
	for (unsigned int i = 0; i < _vertexIndices.size(); i++) {
		glm::vec3 vertex = tempVert[_vertexIndices[i] - 1];
		outVert.push_back(vertex);
	}
	for (unsigned int i = 0; i < UVIn.size(); i++) {
		glm::vec2 UV = tempUV[UVIn[i] - 1];
		outUV.push_back(UV);
	}
	std::cout << "\n";
	for (unsigned int i = 0; i < outVert.size(); i++) {
		std::cout << outVert[i].x << ", " << outVert[i].y << ", " << outVert[i].z << "\n";
	}

	_vertexBuffer = new GLuint;
	glGenBuffers(1, _vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tempVert.data()) * tempVert.size(), static_cast<void*>(tempVert.data()), GL_STATIC_DRAW);
	_vertexIndexBuffer = new GLuint;
	
	glGenBuffers(1, _vertexIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_vertexIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_vertexIndices.data()) * _vertexIndices.size(), static_cast<void*>(_vertexIndices.data()), GL_STATIC_DRAW);

	_UVBuffer = new GLuint;
	glGenBuffers(1, _UVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *_UVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(outUV.data()) * outUV.size(), static_cast<void*>(outUV.data()), GL_STATIC_DRAW);

	_vertSize = (int)outVert.size() / 3;

	_texture = new GLuint;
	*_texture = loadBMP(imgPath);
	_usedEngine = engine;
	_textureID = new GLuint;
	*_textureID = glGetUniformLocation(*_usedEngine->getProgramID(), "textureSampler");

	_loc = glm::vec3(0.0f);
	_rot = glm::vec3(0.0f);
	_scale = glm::vec3(0.0f);
	_modelMatrix = glm::mat4(1.0f);

	_view = _usedEngine->getView();
	_projection = _usedEngine->getProjection();

	_MVP = *_projection * *_view * _modelMatrix;
}
GameObject::~GameObject() {

}
void GameObject::objectPollEvents() {
	_MVP = *_projection * *_view * _modelMatrix;
	

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

	glUniformMatrix4fv(*_usedEngine->getMatrixID(), 1, GL_FALSE, &_MVP[0][0]);
	glDrawElements(
		GL_TRIANGLES,
		_vertexIndices.size(),
		GL_UNSIGNED_SHORT,
		(void*)0
	);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}