#ifndef GAME_H
#define GAME_H

#include <glm\vec2.hpp>
#include <vector>
#include <string>

#include "Camera.h"
#include "SpriteRenderer.h"
#include "PlayerObject.h"
#include "CowObject.h"
#include "ShotObject.h"
#include "Layer.h"

class Game
{
public:
	Game(glm::vec2 windowSize);
	~Game();

	void Initialize();

	void HandleInput(float dt);
	void Update(float dt);
	void Collisions();
	void Render(float dt);

	bool GetIsOver();

	void ShowScoreboard();

private:
	int score;
	bool isOver;
	float spawnCounter;
	float spawnDelay;
	std::vector<CowObject *> cows;
	std::vector<ShotObject *>shots;
	glm::vec2 windowSize;
	glm::vec2 worldSize;
	std::vector<Layer *> layers;

	SpriteRenderer * spriteRenderer;
	PlayerObject * player;
	Camera * camera;

	void PlayerCollisions();
	void CowCollisions();
	void ShotCollisions();

	CowObject * SpawnCow(bool avoidPlayer = false);
};

#endif