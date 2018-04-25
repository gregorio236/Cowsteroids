#include "Layer.h"

Layer::Layer()
{

}

Layer::Layer(Texture sprite, glm::vec2 pos, glm::vec2 size, int z, float parallax, glm::vec2 worldCenter)
{
	this->sprite = sprite;
	this->position = pos;
	this->size = size;
	this->parallax = parallax;
	this->worldCenter = worldCenter;
}

Layer::~Layer()
{

}

void Layer::Draw(SpriteRenderer & renderer, glm::vec2 center)
{
	glm::vec2 distance = (center - this->worldCenter) * this->parallax;
	glm::vec2 drawPos = this->position + distance;
	renderer.DrawSprite(this->sprite, drawPos, this->size, z);
}
