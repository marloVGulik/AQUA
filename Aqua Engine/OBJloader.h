#pragma once
#include "dependencies.h"
#include "indexer.h"

unsigned int loadOBJ(std::string path, std::vector<GLfloat>& outVert, std::vector<GLfloat>& outUV, std::vector<GLfloat>& outNormal, std::vector<unsigned int>& outVBO);