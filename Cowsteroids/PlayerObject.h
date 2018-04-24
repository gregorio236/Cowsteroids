#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(glm::vec2 pos, Texture sprite);
	~PlayerObject();

	void Update(float dt);

	void RotateCW(float dt);
	void RotateCCW(float dt);
	void Move(float dt);
	void Stop(float dt);

private:
	float speed;
	float acceleration;
	float accelerationRate;
	float desacceleration;
	float maxSpeed;
	float rotationSpeed;
};

#endif