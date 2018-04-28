#include "CowObject.h"

CowObject::CowObject(glm::vec2 pos, Texture sprite, float rotation, int tier)
{
	this->position = pos;
	this->tier = tier;
	this->size = glm::vec2(32.0f * tier, 32.0f * tier);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = rotation;
	this->sprite = Sprite(sprite, 4, 1.0f);
	this->COM = glm::vec2(0.4921875f * this->size.x, 0.5f * this->size.y);
	this->radius = 0.4453125f * this->size.x;
	this->speed = 3.0f / tier;
	this->direction = glm::vec2(speed * cos(rotation), speed * sin(rotation));
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
}