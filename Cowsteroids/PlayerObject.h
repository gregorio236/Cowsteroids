#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include <glm\glm.hpp>

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec2 worldSize);
	~PlayerObject();

	void Update(float dt);

private:
	float speed;
	float acceleration;

	glm::vec2 worldSize;
};

#endif