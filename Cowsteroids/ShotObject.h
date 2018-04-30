#ifndef SHOT_OBJECT_H
#define SHOT_OBJECT_H

#include "GameObject.h"
#include "Configuration.h"


class ShotObject : public GameObject
{
public:
	ShotObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config);
	~ShotObject();

	void Update(float dt) override;

private:
	glm::vec2 direction;
};

#endif