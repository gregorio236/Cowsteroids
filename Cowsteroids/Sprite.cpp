#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Texture texture, int frameCount, float frameDuration)
{
	this->texture = texture;
	this->frameCount = frameCount;
	this->frameDuration = frameDuration;
	this->currentFrame = 0;
	this->currentDuration = 0.0f;
}

Sprite::~Sprite()
{

}

void Sprite::Draw(SpriteRenderer & renderer, float z, glm::vec2 pos, glm::vec2 size, float dt, float rotation, glm::vec3 color)
{
	float offset = (float)currentFrame / frameCount;

	renderer.DrawSprite(this->texture, pos, size, z, offset, this->frameCount, rotation, color);

	currentDuration += dt;
	if (currentDuration >= frameDuration)
	{
		currentDuration = 0.0f;
		currentFrame++;
		if (currentFrame == frameCount)
		{
			currentFrame = 0;
		}
	}
}
