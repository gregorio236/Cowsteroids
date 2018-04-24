#include "PlayerObject.h"

#include <GLFW\glfw3.h>
#include <iostream>
#include "InputManager.h"

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec2 worldSize)
{
	this->position = pos;
	this->size = size;
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = 0.0f;
	this->sprite = sprite;
	this->speed = 0.0f;
	this->acceleration = 0.0f;
	this->worldSize = worldSize;
	this->COM = glm::vec2(0.375f * this->size.x, 0.5 * this->size.y);
	this->radius = 0.3671875f * this->size.x;
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::Update(float dt)
{
	float accelerationRate = 25.0f;
	float desacceleration = 10.0f;
	float maxSpeed = 5.0f;
	float rotationSpeed = 5.0f;

	if (InputManager::Held(GLFW_KEY_A))
	{
		rotation -= rotationSpeed * dt;
	}
	if (InputManager::Held(GLFW_KEY_D))
	{
		rotation += rotationSpeed * dt;
	}

	if (InputManager::Held(GLFW_KEY_W))
	{
		acceleration += accelerationRate * dt;
	}
	else
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

	speed += acceleration;

	if (speed > maxSpeed)
	{
		speed = maxSpeed;
	}
	else if (-speed > maxSpeed)
	{
		speed = -maxSpeed;
	}

	glm::vec2 dir(speed * cos(rotation), speed * sin(rotation));

	position += dir;

	if (position.x < 0.0f)
	{
		position.x = 0.0f;
	}
	else if (position.x + size.x > worldSize.x)
	{
		position.x = worldSize.x - size.x;
	}

	if (position.y < 0.0f)
	{
		position.y = 0.0f;
	}
	else if (position.y + size.y > worldSize.y)
	{
		position.y = worldSize.y - size.y;
	}
}
