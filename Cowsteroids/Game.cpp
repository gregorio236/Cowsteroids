#include "Game.h"
#define _USE_MATH_DEFINES

#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <random>
#include <time.h>

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
	for (CowObject * cow : cows)
	{
		delete cow;
	}
	for (ShotObject * shot : shots)
	{
		delete shot;
	}
}

void Game::Initialize()
{
	ResourceManager::LoadShader("../Shaders/vert.GLSL", "../Shaders/frag.GLSL", "sprite");
	ResourceManager::GetShader("sprite").Use().SetUniform("image", 0);

	ResourceManager::LoadTexture("../Assets/background.jpg", false, "background");
	ResourceManager::LoadTexture("../Assets/cow.png", true, "cow");
	ResourceManager::LoadTexture("../Assets/ship.png", true, "ship");
	ResourceManager::LoadTexture("../Assets/shot.png", true, "shot");

	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	player = new PlayerObject(glm::vec2(100.0f, 100.0f), ResourceManager::GetTexture("ship"));

	camera = new Camera();

	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		float x = (rand() % ((int)this->worldSize.x - 200)) + 100;
		float y = (rand() % ((int)this->worldSize.y - 200)) + 100;
		float ang = rand() % 360;
		cows.push_back(new CowObject(glm::vec2(x, y), ResourceManager::GetTexture("cow"), (ang * M_PI) / 180, 4));
	}


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

	if (InputManager::Pressed(GLFW_KEY_SPACE))
	{
		glm::vec2 pos = player->GetPos() + player->GetSize()*0.5f;
		float rot = player->GetRotation();
		shots.push_back(new ShotObject(pos, ResourceManager::GetTexture("shot"), rot));
	}
}

void Game::Update(float dt)
{
	for (CowObject * cow : cows)
	{
		cow->Update(dt);
	}

	for (ShotObject * shot : shots)
	{
		shot->Update(dt);
	}

	player->Update(dt);
	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");
}

void Game::Collisions()
{
	PlayerCollisions();
	CowCollisions();
	ShotCollisions();
}

void Game::Render()
{
	player->Draw(*spriteRenderer);

	for (ShotObject * shot : shots)
	{
		shot->Draw(*spriteRenderer);
	}

	for (CowObject * cow : cows)
	{
		cow->Draw(*spriteRenderer);
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

	if (CollisionManager::Colided(player, cows[0]))
	{

	}
}

void Game::CowCollisions()
{
	for (int i = 0; i < cows.size(); i++)
	{
		CowObject * cow = cows[i];

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

		for (int j = 0; j < shots.size(); j++)
		{
			ShotObject * shot = shots[j];

			if (CollisionManager::Colided(cow, shot))
			{
				delete shot;
				shots.erase(shots.begin() + j);

				int tier = cow->GetTier();
				if (tier > 1)
				{
					cows.push_back(new CowObject(cow->GetPos(), ResourceManager::GetTexture("cow"), cow->GetRotation() - 1, tier - 1));
					cows.push_back(new CowObject(cow->GetPos(), ResourceManager::GetTexture("cow"), cow->GetRotation() + 1, tier - 1));
				}
				delete cow;
				cows.erase(cows.begin() + i);
				i--;

				break;
			}
		}
	}
}

void Game::ShotCollisions()
{
	for (int i = 0; i < shots.size(); i++)
	{
		ShotObject * shot = shots[i];

		bool * collision = CollisionManager::Colided(shot, this->worldSize);

		if (collision[COL_LEFT] || collision[COL_RIGHT] || collision[COL_TOP] || collision[COL_DOWM])
		{
			delete shot;
			shots.erase(shots.begin() + i);
			i--;
		}
	}
}
