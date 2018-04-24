#ifndef COLISION_MANAGER_H
#define COLISION_MANAGER_H

#include <glm\vec2.hpp>

#include "GameObject.h"

enum WorldCollison
{
	COL_LEFT,
	COL_RIGHT,
	COL_TOP,
	COL_DOWM
};

class CollisionManager
{
public:
	static bool Colided(GameObject * obj1, GameObject * obj2);
	static bool * Colided(GameObject * obj, glm::vec2 worldSize);
};

#endif