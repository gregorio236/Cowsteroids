#ifndef SPRITE_H
#define SPRITE_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

class Sprite
{
public:
	Sprite();
	Sprite(Texture texture, int frameCount, float frameDuration);
	~Sprite();

	void Draw(SpriteRenderer & renderer, float z, glm::vec2 pos, glm::vec2 size, float dt, float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));

private:
	Texture texture;
	int frameCount;
	float frameDuration;
	int currentFrame;
	float currentDuration;
};

#endif