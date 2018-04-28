#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Draw(SpriteRenderer & renderer, float z, float dt)
{
	this->sprite.Draw(renderer, z, this->position, this->size, dt, this->rotation, this->color);
}

float GameObject::GetRotation()
{
	return this->rotation;
}

glm::vec2 GameObject::GetPos()
{
	return this->position;
}

void GameObject::SetPos(glm::vec2 pos)
{
	this->position = pos;
}

glm::vec2 GameObject::GetSize()
{
	return this->size;
}

glm::vec2 GameObject::GetCOM()
{
	return this->COM;
}

float GameObject::GetRadius()
{
	return this->radius;
}
