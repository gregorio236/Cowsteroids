#include "ShotObject.h"

ShotObject::ShotObject(glm::vec2 pos, Texture sprite, float rotation)
{
	this->size = glm::vec2(16.0f, 16.0f);
	this->position = pos - size*0.5f;
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = rotation;
	this->sprite = sprite;
	this->COM = glm::vec2(0.484375f * this->size.x, 0.5f * this->size.y);
	this->radius = 0.40625f * this->size.x;
	this->speed = 10.0f;
	this->direction = glm::vec2(speed * cos(rotation), speed * sin(rotation));
}

ShotObject::~ShotObject()
{

}

void ShotObject::Update(float dt)
{
	position += direction;
}
