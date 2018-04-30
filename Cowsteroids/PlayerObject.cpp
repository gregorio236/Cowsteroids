#include "PlayerObject.h"

#include <GLFW\glfw3.h>
#include <iostream>
#include "InputManager.h"

PlayerObject::PlayerObject(glm::vec2 pos, Texture sprite, Configuration config)
	: GameObject(pos, sprite, 0.0f, config)
{
	this->speed = 0.0f;
	this->acceleration = 0.0f;
	this->accelerationRate = std::stof(config["acceleration"]["a"]);
	this->desacceleration = std::stof(config["desacceleration"]["d"]);
	this->maxSpeed = std::stof(config["speed"]["s"]);
	this->rotationSpeed = std::stof(config["rotation"]["r"]);
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::Update(float dt)
{
	speed += acceleration;

	if (speed > maxSpeed)
	{
		speed = maxSpeed;
	}

	glm::vec2 dir(speed * cos(rotation), speed * sin(rotation));

	position += dir;
}

void PlayerObject::RotateCW(float dt)
{
	rotation += rotationSpeed * dt;
}

void PlayerObject::RotateCCW(float dt)
{
	rotation -= rotationSpeed * dt;
}

void PlayerObject::Move(float dt)
{
	acceleration += accelerationRate * dt;
}

void PlayerObject::Stop(float dt)
{
	acceleration = 0.0f;
	if (speed > 0.0f)
	{
		speed -= desacceleration * dt;
	}
	else
	{
		speed = 0.0f;
	}
}
