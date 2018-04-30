#ifndef LAYER_H
#define LAYER_H

#include <glm\vec2.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

class Layer
{
public:
	Layer();
	Layer(Texture sprite, glm::vec2 pos, glm::vec2 size, float z, float parallax, glm::vec2 worldCenter);
	~Layer();

	void Draw(SpriteRenderer & renderer, glm::vec2 center);

private:
	Texture sprite;
	glm::vec2 position;
	glm::vec2 size;
	float z;
	float parallax;
	glm::vec2 worldCenter;
};

#endif