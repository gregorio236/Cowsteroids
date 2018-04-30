#ifndef COW_OBJECT_H
#define COW_OBJECT_H

#include <glm\vec2.hpp>

#include "Configuration.h"
#include "GameObject.h"
#include "Texture.h"

class CowObject : public GameObject
{
public:
	CowObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config, int tier);
	~CowObject();

	int GetTier();

	//Movimenta e gira a vaca
	void Update(float dt) override;

	void BounceHorizontal();
	void BounceVertical();

private:
	//quanto maior o tier, maior e a vaca e menor o movimento
	//quando, por exemplo, uma vaca tier 3 morre, duas tier 2 aparecem
	//o menor tier possivel e 1
	int tier;
	//-1 para anti-horario, 1 para horario
	int rotationDirection;
	glm::vec2 direction;
};

#endif