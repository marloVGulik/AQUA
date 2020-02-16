#include "indexer.hpp"

bool isNear3D(glm::vec3 pos1, glm::vec3 pos2, float difference) {
	if (fabs(pos1.x - pos2.x) < difference && fabs(pos1.y - pos2.y) < difference && fabs(pos1.z - pos2.z) < difference) return true;
	return false;
}
bool isNear2D(glm::vec2 pos1, glm::vec2 pos2, float difference) {
	if (fabs(pos1.x - pos2.x) < difference && fabs(pos1.y - pos2.y) < difference) return true;
	return false;
}

void indexObj(std::vector<glm::vec3>& inVert, std::vector<glm::vec2>& inUV, std::vector<glm::vec3>& inNormal, std::vector<unsigned int>& outVBOIndex, std::vector<glm::vec3>& outVert, std::vector<glm::vec2>& outUV, std::vector<glm::vec3>& outNormal) {
	unsigned int count = 0;

	unsigned int consoleCounter = 0;
	//float MAX_DIFFERENCE_BETWEEN_INDEXER = 0.1f;
	
	std::cout << "Obj size: " << inVert.size() << "\n";
	for (unsigned int i = 0; i < inVert.size(); i++) {
		consoleCounter++;
		if (consoleCounter == 1000) {
			std::cout << "Calculating vert index: " << i << "\n";
			consoleCounter = 0;
		}

		bool shouldAdd = true;
		unsigned int indexedNumberToAdd = 0;
		for (unsigned int j = 0; j < outVert.size(); j++) {
			if(inVert[i] == outVert[j]/* && inUV[i] == outUV[j] && inNormal[i] == outNormal[j]*/) {
			//if(isNear3D(inVert[i], outVert[j], MAX_DIFFERENCE_BETWEEN_INDEXER) && isNear2D(inUV[i], outUV[j], MAX_DIFFERENCE_BETWEEN_INDEXER) && isNear3D(inNormal[i], outNormal[j], MAX_DIFFERENCE_BETWEEN_INDEXER)) {
				//std::cout << "Found something~\n";
				shouldAdd = false;
				indexedNumberToAdd = j;
				j = (unsigned int)outVBOIndex.size();
			}
		}
		if (shouldAdd) {
			//std::cout << "Adding: " << inVert[i].x << ", " << inVert[i].y << ", " << inVert[i].z << "\n";
			outVert.push_back(inVert[i]);
			outUV.push_back(inUV[i]);
			outNormal.push_back(inNormal[i]);

			outVBOIndex.push_back(count);
			count++;
		}
		else {
			//std::cout << "Not adding: " << indexedNumberToAdd << " already includes: " << inVert[i].x << ", " << inVert[i].y << ", " << inVert[i].z << "\n";
			outVBOIndex.push_back(indexedNumberToAdd);
		}
	}
	//std::cout << outVBOIndex.size() << "\n";
	std::cout << outVert.size() << "\n\n";
	//for (int i = 0; i < outVert.size(); i++) {
	//	std::cout << outVert[i].x << ", " << outVert[i].y << ", " << outVert[i].z << "\n";
	//}

	//std::cout << outVBOIndex.size() << "\n\n";
	//for (int i = 0; i < outVBOIndex.size(); i++) {
	//	std::cout << outVBOIndex[i] << " : index\n";
	//	//std::cout << outVert[outVBOIndex[i]].x << ", " << outVert[outVBOIndex[i]].y << ", " << outVert[outVBOIndex[i]].z << "\n";
	//}
}
