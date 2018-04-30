#include "CowObject.h"

#include <random>

CowObject::CowObject(glm::vec2 pos, Texture sprite, float rotation, int tier)
{
	this->position = pos;
	this->tier = tier;
	this->size = glm::vec2(32.0f * tier, 32.0f * tier);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = rotation;
	this->sprite = Sprite(sprite, 6, 0.3f);
	this->COM = glm::vec2(0.5f * this->size.x, 0.515503876f * this->size.y);
	this->radius = 0.34496124f * this->size.x;
	//this->COM = glm::vec2(0.4921875f * this->size.x, 0.5f * this->size.y);
	//this->radius = 0.4453125f * this->size.x;
	this->speed = 2.5f / tier;
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