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
	this->worldSize = glm::vec2(1920.0f, 1080.0f);
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

	ResourceManager::LoadTexture("../Assets/stars.png", true, "stars");
	ResourceManager::LoadTexture("../Assets/cow.png", true, "cow");
	ResourceManager::LoadTexture("../Assets/ship.png", true, "ship");
	ResourceManager::LoadTexture("../Assets/shot.png", true, "shot");
	ResourceManager::LoadTexture("../Assets/planet1.png", true, "planet1");
	ResourceManager::LoadTexture("../Assets/planet2.png", true, "planet2");
	ResourceManager::LoadTexture("../Assets/sun.png", true, "sun");
	ResourceManager::LoadTexture("../Assets/wall.png", true, "wall");

	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	player = new PlayerObject(glm::vec2(this->worldSize.x / 2, this->worldSize.y / 2), ResourceManager::GetTexture("ship"));

	camera = new Camera();

	camera->Update(player->GetPos(), this->windowSize * 0.5f, this->worldSize, "sprite", "projection");

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		float x = (rand() % ((int)this->worldSize.x - 200)) + 100;
		float y = (rand() % ((int)this->worldSize.y - 200)) + 100;
		int ang = rand() % 360;
		cows.push_back(new CowObject(glm::vec2(x, y), ResourceManager::GetTexture("cow"), (ang * M_PI) / 180, 4));
	}

	layers.push_back(new Layer(ResourceManager::GetTexture("wall"), glm::vec2(-10.0f, -10.0f), glm::vec2(1940.0f, 1100.0f), 0, 0.0f, this->worldSize*0.5f));
	layers.push_back(new Layer(ResourceManager::GetTexture("planet1"), glm::vec2(100.0f, 100.0f), glm::vec2(150.0f, 150.0f), -1, 0.1f, this->worldSize*0.5f));
	layers.push_back(new Layer(ResourceManager::GetTexture("planet2"), glm::vec2(1500.0f, 700.0f), glm::vec2(500.0f, 500.0f), -1, 0.2f, this->worldSize*0.5f));
	glm::vec2 sunSize = glm::vec2(50.0f, 50.0f);
	layers.push_back(new Layer(ResourceManager::GetTexture("sun"), ((this->worldSize - sunSize)*0.5f), sunSize, -98, 0.9f, this->worldSize*0.5f));
	layers.push_back(new Layer(ResourceManager::GetTexture("stars"), glm::vec2(0.0f, 0.0f), this->worldSize, -99, 1.0f, this->worldSize*0.5f));
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
	player->Draw(*spriteRenderer, 3);

	for (ShotObject * shot : shots)
	{
		shot->Draw(*spriteRenderer, 2);
	}

	for (CowObject * cow : cows)
	{
		cow->Draw(*spriteRenderer, 1);
	}

	for (Layer * layer : layers)
	{
		layer->Draw(*spriteRenderer, player->GetPos() + player->GetCOM());
	}
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
			cow->direction.x *= -1;
			//cow->SetPos(glm::vec2(this->worldSize.x - cow->GetSize().x, cow->GetPos().y));
		}
		else if (collision[COL_RIGHT])
		{
			cow->direction.x *= -1;
			//cow->SetPos(glm::vec2(0.0f, cow->GetPos().y));
		}

		if (collision[COL_TOP])
		{
			cow->direction.y *= -1;
			//cow->SetPos(glm::vec2(cow->GetPos().x, this->worldSize.y - cow->GetSize().y));
		}
		else if (collision[COL_DOWM])
		{
			cow->direction.y *= -1;
			//cow->SetPos(glm::vec2(cow->GetPos().x, 0.0f));
		}

		for (int j = 0; j < shots.size(); j++)
		{
			ShotObject * shot = shots[j];

			if (CollisionManager::Colided(cow, shot))
			{
				int tier = cow->GetTier();
				if (tier > 1)
				{
					cows.push_back(new CowObject(cow->GetPos(), ResourceManager::GetTexture("cow"), cow->GetRotation() - 1, tier - 1));
					cows.push_back(new CowObject(cow->GetPos(), ResourceManager::GetTexture("cow"), cow->GetRotation() + 1, tier - 1));
				}

				delete shot;
				shots.erase(shots.begin() + j);

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
