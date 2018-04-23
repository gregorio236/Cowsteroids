#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm\glm.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject
{
public:
	GameObject();
	GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), float rotation = 0.0f, glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
	~GameObject();

	void Draw(SpriteRenderer &renderer);

protected:
	glm::vec2 position;
	glm::vec2 size;
	glm::vec2 velocity;
	glm::vec3 color;
	float rotation;

	Texture sprite;
};

#endif