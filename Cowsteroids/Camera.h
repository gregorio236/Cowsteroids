#ifndef CAMERA_H
#define CAMERA_H

#include <glm\vec2.hpp>

#include "GameObject.h"

class Camera
{
public:
	Camera();
	~Camera();

	//Atualiza a posicao da camera
	void Update(glm::vec2 center, glm::vec2 halfSize, glm::vec2 worldSize, const char* shader, const char* uniform);
};

#endif