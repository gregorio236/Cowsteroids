#ifndef GAME_H
#define GAME_H

#include "SpriteRenderer.h"

enum GameState
{
	ACTIVE,
	MENU,
	WIN
};

class Game
{
public:
	Game(int width, int height);
	~Game();

	void SetState(GameState state);
	void SetKey(int key, bool active);

	void Initialize();

	void ProcessInput(float dt);
	void Update(float dt);
	void Render();



private:
	GameState state;
	bool keys[1024];
	int width;
	int height;

	SpriteRenderer* spriteRenderer;
};

#endif