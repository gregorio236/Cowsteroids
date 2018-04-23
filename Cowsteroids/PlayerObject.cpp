#include "PlayerObject.h"

#include <GLFW\glfw3.h>
#include <iostream>
#include "InputManager.h"

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color, float rotation)
{
	this->position = pos;
	this->size = size;
	this->velocity = glm::vec2(0.0f, 0.0f);
	this->color = color;
	this->rotation = rotation;
	this->sprite = sprite;
	this->speed = 0.0f;
	this->acceleration = 0.0f;
	this->maxSpeed = 5.0f;
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::HandleInput(float dt)
{
	if (InputManager::Held(GLFW_KEY_A))
	{
		rotation -= dt;
	}
	if (InputManager::Held(GLFW_KEY_D))
	{
		rotation += dt;
	}
	if (InputManager::Held(GLFW_KEY_W))
	{
		acceleration += dt;
	}
	if (InputManager::Held(GLFW_KEY_S))
	{
		acceleration -= dt;
	}

	if (!InputManager::Held(GLFW_KEY_W) && !InputManager::Held(GLFW_KEY_S))
	{
		acceleration = 0.0f;
		if (speed > 0.05f)
		{
			speed -= dt;
		}
		else if (speed < -0.05f)
		{
			speed += dt;
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
	std::cout << abs(speed) << std::endl;

	position += dir;
}
