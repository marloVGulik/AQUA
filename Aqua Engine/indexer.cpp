#include "indexer.hpp"

bool isNear3D(glm::vec3 pos1, glm::vec3 pos2, float difference) {
	if (fabs(pos1.x - pos2.x) < difference && fabs(pos1.y - pos2.y) < difference && fabs(pos1.z - pos2.z) < difference) return true;
	return false;
}
bool isNear2D(glm::vec2 pos1, glm::vec2 pos2, float difference) {
	if (fabs(pos1.x - pos2.x) < difference && fabs(pos1.y - pos2.y) < difference) return true;
	return false;
}

struct VertexPacked {
	glm::vec3 pos;
	glm::vec2 UV;
	glm::vec3 normal;

	bool operator<(const VertexPacked pvertex) const {
		return memcmp((void*)this, (void*)&pvertex, sizeof(VertexPacked)) > 0;
	}
};
bool getSimVertex(VertexPacked& pvertex, std::map<VertexPacked, unsigned int>& vertexToOutIndex, unsigned int& result) {
	std::map<VertexPacked, unsigned int>::iterator it = vertexToOutIndex.find(pvertex);
	if (it == vertexToOutIndex.end()) {
		return false;
	}
	else {
		result = it->second;
		return true;
	}
}


void indexObj(std::vector<glm::vec3>& inVert, std::vector<glm::vec2>& inUV, std::vector<glm::vec3>& inNormal, std::vector<unsigned int>& outVBOIndex, std::vector<glm::vec3>& outVert, std::vector<glm::vec2>& outUV, std::vector<glm::vec3>& outNormal) {
	unsigned int count = 0;

	unsigned int consoleCounter = 0;
	//float MAX_DIFFERENCE_BETWEEN_INDEXER = 0.1f;

	std::map<VertexPacked, unsigned int> vertexToOutIndex;
	
	std::cout << "Obj size: " << inVert.size() << "\n";
	for (unsigned int i = 0; i < inVert.size(); i++) {
		/*consoleCounter++;
		if (consoleCounter == 1000) {
			std::cout << "Calculating vert index: " << i << "\n";
			consoleCounter = 0;
		}*/

		unsigned int indexedNumberToAdd = 0;
		VertexPacked currentPVertex = { inVert[i], inUV[i], inNormal[i] };
		bool shouldAdd = getSimVertex(currentPVertex, vertexToOutIndex, indexedNumberToAdd);
		
		if (!shouldAdd) {
			//std::cout << "Adding: " << inVert[i].x << ", " << inVert[i].y << ", " << inVert[i].z << "\n";
			outVert.push_back(inVert[i]);
			outUV.push_back(inUV[i]);
			outNormal.push_back(inNormal[i]);
			unsigned int newIndex = (unsigned int)outVert.size() - 1;
			outVBOIndex.push_back(count);
			vertexToOutIndex[currentPVertex] = count;
			count++;
		}
		else {
			//std::cout << "Not adding: " << indexedNumberToAdd << " already includes: " << inVert[i].x << ", " << inVert[i].y << ", " << inVert[i].z << "\n";
			outVBOIndex.push_back(indexedNumberToAdd);
		}
	}
}
