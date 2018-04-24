#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm\glm.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Draw(SpriteRenderer &renderer);

	glm::vec2 GetPos();
	glm::vec2 GetCOM();
	float GetRadius();

protected:
	glm::vec2 position;
	glm::vec2 size;
	glm::vec3 color;
	float rotation;

	Texture sprite;

	glm::vec2 COM;
	float radius;
};

#endif