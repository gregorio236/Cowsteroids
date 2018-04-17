#include "Game.h"

Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
}

Game::~Game()
{

}

void Game::SetState(GameState state)
{
	this->state = state;
}

void Game::SetKey(int key, bool active)
{
	this->keys[key] = active;
}

void Game::Initialize()
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Update(float dt)
{

}

void Game::Render()
{

}