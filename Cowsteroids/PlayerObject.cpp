#include "PlayerObject.h"

#include <GLFW\glfw3.h>
#include <iostream>
#include "InputManager.h"

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color, float rotation)
{
	this->position = pos;
	this->size = size;
	this->color = color;
	this->rotation = rotation;
	this->sprite = sprite;
	this->speed = 0.0f;
	this->acceleration = 0.0f;
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
}
