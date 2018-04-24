#include "Game.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GLFW\glfw3.h>

#include "InputManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"

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

	player = new PlayerObject(glm::vec2(100.0f, 100.0f), ResourceManager::GetTexture("ship"));

	camera = new Camera();

	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");

	cows.push_back(new CowObject(glm::vec2(300.0f, 200.0f), ResourceManager::GetTexture("cow"), (65 * M_PI) / 180, 4));
}

void Game::HandleInput(float dt)
{
	if (InputManager::Held(GLFW_KEY_A))
	{
		player->RotateCCW(dt);
	}
	if (InputManager::Held(GLFW_KEY_D))
	{
		player->RotateCW(dt);
	}

	if (InputManager::Held(GLFW_KEY_W))
	{
		player->Move(dt);
	}
	else
	{
		player->Stop(dt);
	}
}

void Game::Update(float dt)
{
	for (CowObject * c : cows)
	{
		c->Update(dt);
	}

	player->Update(dt);
	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");
}

void Game::Collisions()
{
	PlayerCollisions();
	CowCollisions();
}

void Game::Render()
{
	player->Draw(*spriteRenderer);

	for (CowObject * c : cows)
	{
		c->Draw(*spriteRenderer);
	}

	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), this->worldSize);
}

void Game::PlayerCollisions()
{
	bool * playerCol = CollisionManager::Colided(player, this->worldSize);

	if (playerCol[COL_LEFT])
	{
		player->SetPos(glm::vec2(0.0f, player->GetPos().y));
	}
	else if (playerCol[COL_RIGHT])
	{
		player->SetPos(glm::vec2(this->worldSize.x - player->GetSize().x, player->GetPos().y));
	}

	if (playerCol[COL_TOP])
	{
		player->SetPos(glm::vec2(player->GetPos().x, 0.0f));
	}
	else if (playerCol[COL_DOWM])
	{
		player->SetPos(glm::vec2(player->GetPos().x, this->worldSize.y - player->GetSize().y));
	}
}

void Game::CowCollisions()
{
	for (CowObject * cow : cows)
	{
		bool * collision = CollisionManager::Colided(cow, this->worldSize);

		if (collision[COL_LEFT])
		{
			cow->SetPos(glm::vec2(this->worldSize.x - cow->GetSize().x, cow->GetPos().y));
		}
		else if (collision[COL_RIGHT])
		{
			cow->SetPos(glm::vec2(0.0f, cow->GetPos().y));

		}

		if (collision[COL_TOP])
		{
			cow->SetPos(glm::vec2(cow->GetPos().x, this->worldSize.y - cow->GetSize().y));

		}
		else if (collision[COL_DOWM])
		{
			cow->SetPos(glm::vec2(cow->GetPos().x, 0.0f));
		}
	}
}
