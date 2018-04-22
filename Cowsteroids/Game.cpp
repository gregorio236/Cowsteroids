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
}

void Game::ProcessInput(float dt)
{

}

void Game::Update(float dt)
{

}

void Game::Render()
{
	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(this->width, this->height));
}