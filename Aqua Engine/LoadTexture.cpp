#include "LoadTexture.hpp"

GLuint loadBMP(std::string path) {
	unsigned char header[54];
	unsigned int DPos;
	unsigned int w, h;
	unsigned int size;

	unsigned char* data;

	FILE* imgFile = fopen(path.c_str(), "rb");
	if (!imgFile) { std::cout << "ERROR OPENING FILE!\n"; return false; }
	if (fread(header, 1, 54, imgFile) != 54) { std::cout << "ERROR IN FILE!\n"; return false; }
	if (header[0] != 'B' || header[1] != 'M') { std::cout << "ERROR IN FILE!\n"; return false; }

	DPos = *(int*)&(header[0x0A]);
	size = *(int*)&(header[0x22]);
	w = *(int*)&(header[0x12]);
	h = *(int*)&(header[0x16]);

	if (size == 0) { size = w * h * 3; }
	if (DPos == 0) { DPos = 54; }

	data = new unsigned char[size];
	fread(data, 1, size, imgFile);
	fclose(imgFile);

	GLuint TID;
	glGenTextures(1, &TID);
	glBindTexture(GL_TEXTURE_2D, TID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	return TID;
}

GLuint loadDDS(std::string path) {
	unsigned char header[124];

	FILE* imgFile;
	imgFile = fopen(path.c_str(), "rb");

	if (imgFile == NULL) {
		std::cout << "ERROR OPENING TEXTURE FILE!\n";
		return false;
	}

	char FCode[4];
	fread(FCode, 1, 4, imgFile);
	if (strncmp(FCode, "DDS", 4) != 0) {
		fclose(imgFile);
		return 0;
	}
	fread(&header, 124, 1, imgFile);

	unsigned int h = *(unsigned int*)&(header[8]);
	unsigned int w = *(unsigned int*)&(header[12]);
	unsigned int linearSize = *(unsigned int*)&(header[16]);
	unsigned int mipMapCount = *(unsigned int*)&(header[24]);
	unsigned int fourCC = *(unsigned int*)&(header[80]);

	unsigned char* buffer;
	unsigned int BSize;

	BSize = mipMapCount > 1 ? linearSize * 2 : linearSize;
	buffer = (unsigned char*)malloc(BSize * sizeof(unsigned char));
	fread(buffer, 1, BSize, imgFile);

	fclose(imgFile);
	return 0;
}