#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>

#include "GameObject.h"

class Camera
{
public:
	Camera();
	~Camera();

	void Update(glm::vec2 center, glm::vec2 size, const char* shader, const char* uniform);
};

#endif