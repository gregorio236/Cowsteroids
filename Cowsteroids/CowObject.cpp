#include "CowObject.h"

#include <random>

CowObject::CowObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config, int tier)
	: GameObject(pos, sprite, rotation, config)
{
	this->tier = tier;
	this->size *= tier;
	this->speed /= tier;

	float comX = std::stof(config["com"]["x"]);
	float comY = std::stof(config["com"]["y"]);
	this->COM = glm::vec2(comX * this->size.x, comY* this->size.y);

	this->radius = std::stof(config["radius"]["r"]) * this->size.x;

	this->direction = glm::vec2(speed * cos(rotation), speed * sin(rotation));
	this->rotationDirection = rand() % 2 == 0 ? -1 : 1;
}

CowObject::~CowObject()
{

}

int CowObject::GetTier()
{
	return this->tier;
}

void CowObject::Update(float dt)
{
	this->position += this->direction;
	this->rotation += dt * rotationDirection;
}