#ifndef COW_OBJECT_H
#define COW_OBJECT_H

#include "GameObject.h"
#include "Configuration.h"

class CowObject : public GameObject
{
public:
	CowObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config, int tier);
	~CowObject();

	int GetTier();

	void Update(float dt) override;

	glm::vec2 direction;

private:
	int tier;
	int rotationDirection;

};

#endif