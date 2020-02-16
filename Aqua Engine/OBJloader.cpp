#include "OBJloader.hpp"

unsigned int loadOBJfile(std::string path, std::vector<glm::vec3> &outVert, std::vector<glm::vec2> &outUV, std::vector<glm::vec3> &outNormal, std::vector<unsigned int> &outVBO) {
	std::vector<unsigned int> vertexIn, UVIn, normalIn;
	std::vector<glm::vec3> tempVert;
	std::vector<glm::vec2> tempUV;
	std::vector<glm::vec3> tempNormals;

	FILE* objFile = fopen(path.c_str(), "r");
	if (objFile == NULL) {
		std::cout << "Error opening file!\n";
		return 0;
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
				return 0;
			}
			//std::cout << vertexIndex[0] << "/" << uvIndex[0] << "/" << normalIndex[0] << " ";
			//std::cout << vertexIndex[0] << " " << vertexIndex[1] << " " << vertexIndex[2] << "\n";
			if (vertexIndex[0] == 0 || vertexIndex[1] == 0 || vertexIndex[2] == 0) {
				std::cout << "reading error! " << vertexIndex[0] << "/" << vertexIndex[1] << "/" << vertexIndex[2] << "\n";
			}
			vertexIn.push_back(vertexIndex[0] - 1);
			vertexIn.push_back(vertexIndex[1] - 1);
			vertexIn.push_back(vertexIndex[2] - 1);

			//std::cout << vertexIndex[1] << "/" << uvIndex[1] << "/" << normalIndex[1] << " ";
			UVIn.push_back(uvIndex[0] - 1);
			UVIn.push_back(uvIndex[1] - 1);
			UVIn.push_back(uvIndex[2] - 1);

			//std::cout << vertexIndex[2] << "/" << uvIndex[2] << "/" << normalIndex[2] << "\n";
			normalIn.push_back(normalIndex[0] - 1);
			normalIn.push_back(normalIndex[1] - 1);
			normalIn.push_back(normalIndex[2] - 1);
		}
		else {
			//std::cout << "test\n";
		}
	}
	fclose(objFile);

	std::vector<glm::vec3> tempOutVert;
	std::vector<glm::vec2> tempOutUV;
	std::vector<glm::vec3> tempOutNormal;
	for (unsigned int i = 0; i < vertexIn.size(); i++) {
		if (vertexIn[i] == -1) {
			std::cout << "ERROR AT " << i << "\n";
		}
		glm::vec3 vertex = tempVert[vertexIn[i]];
		tempOutVert.push_back(vertex);


		glm::vec2 UV = tempUV[UVIn[i]];
		tempOutUV.push_back(UV);

		glm::vec3 normal = tempNormals[normalIn[i]];
		tempOutNormal.push_back(normal);
	}

	indexObj(tempOutVert, tempOutUV, tempOutNormal, outVBO, outVert, outUV, outNormal);

	return (unsigned int)outVBO.size();
}