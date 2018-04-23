#include "Game.h"

#include <glm\glm.hpp>

#include "ResourceManager.h"

Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
}

Game::~Game()
{
	delete spriteRenderer;
	delete player;
}

void Game::SetState(GameState state)
{
	this->state = state;
}

void Game::Initialize()
{
	ResourceManager::LoadShader("../Shaders/vert.GLSL", "../Shaders/frag.GLSL", "sprite");
	ResourceManager::GetShader("sprite").Use().SetUniform("image", 0);

	ResourceManager::LoadTexture("../Assets/background.jpg", false, "background");
	ResourceManager::LoadTexture("../Assets/cow.png", true, "cow");
	ResourceManager::LoadTexture("../Assets/ship.png", true, "ship");

	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	player = new PlayerObject(glm::vec2(100.0f, 100.0f), glm::vec2(32.0f, 32.0f), ResourceManager::GetTexture("ship"));

	camera = new Camera();

	camera->Update(player->GetPos(), glm::vec2(this->width, this->height), "sprite", "projection");
}

void Game::Update(float dt)
{
	player->Update(dt);
	camera->Update(player->GetPos(), glm::vec2(this->width, this->height), "sprite", "projection");
}

void Game::Render()
{
	player->Draw(*spriteRenderer);
	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(2000.0f, 2000.0f));
}