#pragma once;
#include "dependencies.h"
#define MAX_DIFFERENCE_BETWEEN_INDEXER 0.001

void indexObj(
	std::vector<GLfloat>& inVert,
	std::vector<GLfloat>& inUV,
	std::vector<GLfloat>& inNormal,

	std::vector<unsigned int>& outVBOIndex,
	std::vector<GLfloat>& outVert,
	std::vector<GLfloat>& outUV,
	std::vector<GLfloat>& outNormal
);