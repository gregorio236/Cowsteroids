#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include <glm\glm.hpp>

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), float rotation = 0.0f);
	~PlayerObject();

	void HandleInput(float dt);

private:
	float speed;
	float acceleration;
	float maxSpeed;
};

#endif