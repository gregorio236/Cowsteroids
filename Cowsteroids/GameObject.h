#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <string>

#include "Configuration.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject
{
public:
	GameObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config);
	~GameObject();

	float GetRotation();
	glm::vec2 GetPos();
	void SetPos(glm::vec2 pos);
	glm::vec2 GetSize();
	glm::vec2 GetCOM();
	float GetRadius();

	void Draw(SpriteRenderer &renderer, float z, float dt);

	virtual void Update(float dt);

protected:
	glm::vec2 position;
	glm::vec2 size;
	glm::vec3 color;
	float rotation;
	float speed;

	Sprite sprite;

	glm::vec2 COM;
	float radius;
};

#endif