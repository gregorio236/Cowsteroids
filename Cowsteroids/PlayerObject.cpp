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

void PlayerObject::HandleInput(float dt)
{
	float accelerationRate = 25.0f;
	float desacceleration = 10.0f;
	float maxSpeed = 5.0f;
	float rotationSpeed = 5.0f;

	if (InputManager::Held(GLFW_KEY_A))
	{
		this->rotation -= rotationSpeed * dt;
	}
	if (InputManager::Held(GLFW_KEY_D))
	{
		this->rotation += rotationSpeed * dt;
	}
	if (InputManager::Held(GLFW_KEY_W))
	{
		this->acceleration += accelerationRate * dt;
	}
	if (InputManager::Held(GLFW_KEY_S))
	{
		this->acceleration -= accelerationRate * dt;
	}

	if (!InputManager::Held(GLFW_KEY_W) && !InputManager::Held(GLFW_KEY_S))
	{
		this->acceleration = 0.0f;
		if (this->speed > 0.05f)
		{
			this->speed -= desacceleration * dt;
		}
		else if (this->speed < -0.05f)
		{
			this->speed += desacceleration * dt;
		}
		else
		{
			this->speed = 0.0f;
		}
	}

	this->speed += this->acceleration;

	if (this->speed > maxSpeed)
	{
		this->speed = maxSpeed;
	}
	else if (-this->speed > maxSpeed)
	{
		this->speed = -maxSpeed;
	}

	glm::vec2 dir(this->speed * cos(this->rotation), this->speed * sin(this->rotation));

	this->position += dir;
}
