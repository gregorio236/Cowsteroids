#ifndef CAMERA_H
#define CAMERA_H

#include <glm\vec2.hpp>

class Camera
{
public:
	//Atualiza a posicao da camera
	static void Update(glm::vec2 center, glm::vec2 halfSize, const char* shader, const char* uniform);
};

#endif