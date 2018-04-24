#include "Game.h"

#include "ResourceManager.h"

Game::Game(glm::vec2 windowSize)
{
	this->windowSize = windowSize;
	this->worldSize = glm::vec2(2000.0f, 2000.0f);
}

Game::~Game()
{
	delete spriteRenderer;
	delete player;
	delete camera;
}

void Game::Initialize()
{
	ResourceManager::LoadShader("../Shaders/vert.GLSL", "../Shaders/frag.GLSL", "sprite");
	ResourceManager::GetShader("sprite").Use().SetUniform("image", 0);

	ResourceManager::LoadTexture("../Assets/background.jpg", false, "background");
	ResourceManager::LoadTexture("../Assets/cow.png", true, "cow");
	ResourceManager::LoadTexture("../Assets/ship.png", true, "ship");

	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	player = new PlayerObject(glm::vec2(100.0f, 100.0f), glm::vec2(32.0f, 32.0f), ResourceManager::GetTexture("ship"), this->worldSize);

	camera = new Camera();

	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");
}

void Game::Update(float dt)
{
	player->Update(dt);
	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");
}

void Game::Render()
{
	player->Draw(*spriteRenderer);
	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), this->worldSize);
}