#include "PlayerObject.h"

#include <GLFW\glfw3.h>
#include <iostream>
#include "InputManager.h"

PlayerObject::PlayerObject(glm::vec2 pos, Texture sprite)
{
	this->position = pos;
	this->size = glm::vec2(64.0f,64.0f);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = 0.0f;
	this->sprite = sprite;
	this->speed = 0.0f;
	this->acceleration = 0.0f;
	this->COM = glm::vec2(0.375f * this->size.x, 0.5 * this->size.y);
	this->radius = 0.3671875f * this->size.x;
	this->accelerationRate = 25.0f;
	this->desacceleration = 10.0f;
	this->maxSpeed = 5.0f;
	this->rotationSpeed = 5.0f;
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
