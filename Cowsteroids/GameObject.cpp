#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Draw(SpriteRenderer & renderer)
{
	renderer.DrawSprite(this->sprite, this->position, this->size, this->rotation, this->color);
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
	return COM;
}

float GameObject::GetRadius()
{
	return radius;
}
