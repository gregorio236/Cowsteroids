#include "CowObject.h"

#include <random>
#include <string>

CowObject::CowObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config, int tier)
	: GameObject(pos, sprite, rotation, config)
{
	this->tier = tier;
	//aumenta o tamanho dependendo do tier
	this->size *= tier;
	//diminui a velocidade conforme o tier
	this->speed /= tier;

	//o centro de massa tem que ser atualziado para o novo tamanho
	float comX = std::stof(config["com"]["x"]);
	float comY = std::stof(config["com"]["y"]);
	this->COM = glm::vec2(comX * this->size.x, comY * this->size.y);

	//o raio tem que ser atualizado para o novo tamanho
	this->radius = std::stof(config["radius"]["r"]) * this->size.x;

	//a direcao de movimento
	this->direction = glm::vec2(speed * cos(rotation), speed * sin(rotation));
	//a direcao de rotacao e aleatoria
	this->rotationDirection = rand() % 2 == 0 ? -1 : 1;
}

CowObject::~CowObject()
{

}

int CowObject::GetTier()
{
	return this->tier;
}

void CowObject::Update(float dt)
{
	this->position += this->direction;
	this->rotation += dt * rotationDirection;
}

void CowObject::BounceHorizontal()
{
	this->direction.x *= -1;
}

void CowObject::BounceVertical()
{
	this->direction.y *= -1;
}
