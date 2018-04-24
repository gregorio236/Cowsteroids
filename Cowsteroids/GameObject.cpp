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

glm::vec2 GameObject::GetPos()
{
	return this->position;
}

glm::vec2 GameObject::GetCOM()
{
	return COM;
}

float GameObject::GetRadius()
{
	return radius;
}
