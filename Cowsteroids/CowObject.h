#ifndef COW_OBJECT_H
#define COW_OBJECT_H

#include "GameObject.h"

class CowObject : public GameObject
{
public:
	CowObject(glm::vec2 pos, Texture sprite, float rotation, int tier);
	~CowObject();

	int GetTier();

	void Update(float dt);

private:
	glm::vec2 direction;
	float speed;
	int tier;
};

#endif