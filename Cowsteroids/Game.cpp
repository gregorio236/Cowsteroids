#include "Game.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "ResourceManager.h"

Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
}

Game::~Game()
{
	delete spriteRenderer;
}

void Game::SetState(GameState state)
{
	this->state = state;
}

void Game::Initialize()
{
	ResourceManager::LoadShader("../Shaders/vert.GLSL", "../Shaders/frag.GLSL", "sprite");

	glm::mat4 projection = glm::ortho(0.0f, (float)this->width, (float)this->height, 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetUniform("image", 0);
	ResourceManager::GetShader("sprite").SetUniform("projection", projection);

	ResourceManager::LoadTexture("../Assets/block.png", true, "block");
	ResourceManager::LoadTexture("../Assets/blockSolid.png", true, "blockSolid");
	ResourceManager::LoadTexture("../Assets/background.jpg", false, "background");
	ResourceManager::LoadTexture("../Assets/paddle.png", true, "paddle");
	ResourceManager::LoadTexture("../Assets/awesomeface.png", true, "ball");

	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	player = new PlayerObject(glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 100.0f), ResourceManager::GetTexture("ball"));
}

void Game::ProcessInput(float dt)
{
	player->HandleInput(dt);
}

void Game::Update(float dt)
{

}

void Game::Render()
{
	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(this->width, this->height));
	player->Draw(*spriteRenderer);
}