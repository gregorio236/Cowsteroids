#include "ShotObject.h"

ShotObject::ShotObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config)
	: GameObject(pos, sprite, rotation, config)
{
	this->position = pos - size * 0.5f;
	this->direction = glm::vec2(speed * cos(rotation), speed * sin(rotation));
}

ShotObject::~ShotObject()
{

}

void ShotObject::Update(float dt)
{
	position += direction;
}
