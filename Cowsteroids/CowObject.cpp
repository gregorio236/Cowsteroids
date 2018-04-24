#include "CowObject.h"

CowObject::CowObject(glm::vec2 pos, Texture sprite, float rotation, int tier)
{
	this->position = pos;
	this->tier = tier;
	this->size = glm::vec2(32.0f * tier, 32.0f * tier);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = rotation;
	this->sprite = sprite;
	this->COM = glm::vec2(0.375f * this->size.x, 0.5 * this->size.y);
	this->radius = 0.3671875f * this->size.x;
	this->speed = 3.0f / tier;
}

CowObject::~CowObject()
{

}

void CowObject::Update(float dt)
{
	glm::vec2 direction(speed * cos(rotation), speed * sin(rotation));
	position += direction;
}