#include "GameObject.h"

GameObject::GameObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config)
{
	this->position = pos;

	float sizeX = std::stof(config["size"]["x"]);
	float sizeY = std::stof(config["size"]["y"]);
	this->size = glm::vec2(sizeX, sizeY);

	this->color = glm::vec3(1.0f, 1.0f, 1.0f);

	this->rotation = rotation;

	float frames = std::stof(config["sprite"]["frames"]);
	float speed = std::stof(config["sprite"]["speed"]);
	this->sprite = Sprite(sprite, frames, speed);

	float comX = std::stof(config["com"]["x"]);
	float comY = std::stof(config["com"]["y"]);
	this->COM = glm::vec2(comX * this->size.x, comY* this->size.y);

	this->radius = std::stof(config["radius"]["r"]) * this->size.x;

	this->speed = std::stof(config["speed"]["s"]);
}

GameObject::~GameObject()
{

}

void GameObject::Draw(SpriteRenderer & renderer, float z, float dt)
{
	this->sprite.Draw(renderer, z, this->position, this->size, dt, this->rotation, this->color);
}

void GameObject::Update(float dt)
{

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
