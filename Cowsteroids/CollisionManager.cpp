#include "CollisionManager.h"

bool CollisionManager::Colided(GameObject * obj1, GameObject * obj2)
{
	glm::vec2 pos1 = obj1->GetPos() + obj1->GetCOM();
	glm::vec2 pos2 = obj2->GetPos() + obj2->GetCOM();
	//colisao entre dois circulos
	float dist = glm::distance(pos1, pos2);

	return (dist <= obj1->GetRadius() + obj2->GetRadius());
}

bool * CollisionManager::Colided(GameObject * obj, glm::vec2 worldSize)
{
	bool collision[4] = { false, false, false, false };

	if (obj->GetPos().x < 0.0f)
	{
		collision[COL_LEFT] = true;
	}
	else if (obj->GetPos().x + obj->GetSize().x > worldSize.x)
	{
		collision[COL_RIGHT] = true;
	}

	if (obj->GetPos().y < 0.0f)
	{
		collision[COL_TOP] = true;
	}
	else if (obj->GetPos().y + obj->GetSize().y > worldSize.y)
	{
		collision[COL_DOWM] = true;
	}

	return collision;
}
