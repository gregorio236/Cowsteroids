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
	this->desaccelerationRate = std::stof(config["desacceleration"]["d"]);
	this->maxSpeed = std::stof(config["speed"]["s"]);
	this->rotationSpeed = std::stof(config["rotation"]["r"]);
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::Update(float dt)
{
	this->speed += this->acceleration;

	if (this->speed > this->maxSpeed)
	{
		this->speed = this->maxSpeed;
	}

	glm::vec2 dir(this->speed * cos(this->rotation), this->speed * sin(this->rotation));

	this->position += dir;
}

void PlayerObject::RotateCW(float dt)
{
	this->rotation += this->rotationSpeed * dt;
}

void PlayerObject::RotateCCW(float dt)
{
	this->rotation -= this->rotationSpeed * dt;
}

void PlayerObject::Move(float dt)
{
	this->acceleration += this->accelerationRate * dt;
}

void PlayerObject::Stop(float dt)
{
	this->acceleration = 0.0f;
	if (this->speed > 0.0f)
	{
		this->speed -= this->desaccelerationRate * dt;
	}
	else
	{
		this->speed = 0.0f;
	}
}
