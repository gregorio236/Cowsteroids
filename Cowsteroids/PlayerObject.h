#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "GameObject.h"
#include "Configuration.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(glm::vec2 pos, Texture sprite, Configuration config);
	~PlayerObject();

	void Update(float dt) override;

	void RotateCW(float dt);
	void RotateCCW(float dt);
	void Move(float dt);
	void Stop(float dt);

private:
	float acceleration;
	float accelerationRate;
	float desacceleration;
	float maxSpeed;
	float rotationSpeed;
};

#endif