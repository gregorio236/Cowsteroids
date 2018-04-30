#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include <glm\vec2.hpp>

#include "Configuration.h"
#include "GameObject.h"
#include "Texture.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(glm::vec2 pos, Texture sprite, Configuration config);
	~PlayerObject();

	//movimenta na direcao que esta virado
	void Update(float dt) override;

	void RotateCW(float dt);
	void RotateCCW(float dt);
	void Move(float dt);
	void Stop(float dt);

private:
	float acceleration;
	float accelerationRate;
	float desaccelerationRate;
	float maxSpeed;
	float rotationSpeed;
};

#endif