#pragma once
#include "dependencies.hpp"
#include "indexer.hpp"

unsigned int loadOBJfile(std::string path, std::vector<glm::vec3>& outVert, std::vector<glm::vec2>& outUV, std::vector<glm::vec3>& outNormal, std::vector<unsigned int>& outVBO);
