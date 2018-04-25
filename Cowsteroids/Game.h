#ifndef GAME_H
#define GAME_H

#include <glm\vec2.hpp>
#include <vector>

#include "Camera.h"
#include "SpriteRenderer.h"
#include "PlayerObject.h"
#include "CowObject.h"
#include "ShotObject.h"

class Game
{
public:
	Game(glm::vec2 windowSize);
	~Game();

	void Initialize();

	void HandleInput(float dt);
	void Update(float dt);
	void Collisions();
	void Render();

private:
	std::vector<CowObject *> cows;
	std::vector<ShotObject *>shots;
	glm::vec2 windowSize;
	glm::vec2 worldSize;

	SpriteRenderer * spriteRenderer;
	PlayerObject * player;
	Camera * camera;

	void PlayerCollisions();
	void CowCollisions();
	void ShotCollisions();
};

#endif