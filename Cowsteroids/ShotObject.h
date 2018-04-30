#ifndef SHOT_OBJECT_H
#define SHOT_OBJECT_H

#include <glm\vec2.hpp>

#include "Configuration.h"
#include "GameObject.h"
#include "Texture.h"

class ShotObject : public GameObject
{
public:
	ShotObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config);
	~ShotObject();

	//atualiza a posicao
	void Update(float dt) override;

private:
	//direcao de movimento
	glm::vec2 direction;
};

#endif