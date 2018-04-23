#include "GameObject.h"

GameObject::GameObject()
{
	this->position = glm::vec2(0.0f, 0.0f);
	this->size = glm::vec2(0.0f, 0.0f);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);
	this->rotation = 0.0f;
}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color, float rotation)
{
	this->position = pos;
	this->size = size;
	this->color = color;
	this->rotation = rotation;
	this->sprite = sprite;
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
