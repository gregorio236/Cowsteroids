#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include <glm\vec2.hpp>

#include "Camera.h"
#include "CowObject.h"
#include "Layer.h"
#include "PlayerObject.h"
#include "ShotObject.h"
#include "SpriteRenderer.h"

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
	std::vector<CowObject *> cows;
	std::vector<ShotObject *> shots;
	glm::vec2 windowSize;
	glm::vec2 worldSize;
	std::vector<Layer *> layers;

	SpriteRenderer * spriteRenderer;
	PlayerObject * player;
	Camera * camera;

	Configuration cowConfig;
	Configuration playerConfig;
	Configuration shotConfig;
	Configuration planetsConfig;

	void PlayerCollisions();
	void CowCollisions();
	void ShotCollisions();

	CowObject * SpawnCow(bool avoidPlayer = false);
};

#endif