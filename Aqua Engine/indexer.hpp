#pragma once;
#include "dependencies.hpp"
#define MAX_DIFFERENCE_BETWEEN_INDEXER 0.2f

bool isNear3D(glm::vec3 pos1, glm::vec3 pos2, float difference);

void indexObj(
	std::vector<glm::vec3>& inVert,
	std::vector<glm::vec2>& inUV,
	std::vector<glm::vec3>& inNormal,
	std::vector<unsigned int>& outVBOIndex,
	std::vector<glm::vec3>& outVert,
	std::vector<glm::vec2>& outUV,
	std::vector<glm::vec3>& outNormal
);