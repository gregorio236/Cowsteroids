#ifndef SHOT_OBJECT_H
#define SHOT_OBJECT_H

#include "GameObject.h"

class ShotObject : public GameObject
{
public:
	ShotObject(glm::vec2 pos, Texture sprite, float rotation);
	~ShotObject();

	void Update(float dt);

private:
	float speed;
	glm::vec2 direction;
};

#endif