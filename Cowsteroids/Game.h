#ifndef GAME_H
#define GAME_H

#include <glm\glm.hpp>

#include "Camera.h"
#include "SpriteRenderer.h"
#include "PlayerObject.h"

class Game
{
public:
	Game(glm::vec2 windowSize);
	~Game();

	void Initialize();

	void Update(float dt);
	void Render();

private:
	glm::vec2 windowSize;
	glm::vec2 worldSize;

	SpriteRenderer * spriteRenderer;

	PlayerObject * player;

	Camera * camera;
};

#endif