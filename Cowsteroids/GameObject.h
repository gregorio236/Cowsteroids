#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	float GetRotation();
	glm::vec2 GetPos();
	void SetPos(glm::vec2 pos);
	glm::vec2 GetSize();
	glm::vec2 GetCOM();
	float GetRadius();

	void Draw(SpriteRenderer &renderer);

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