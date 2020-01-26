#include "LoadBMP.h"

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

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return TID;
}
