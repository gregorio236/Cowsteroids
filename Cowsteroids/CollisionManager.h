#ifndef COLISION_MANAGER_H
#define COLISION_MANAGER_H

#include <glm\vec2.hpp>

#include "GameObject.h"

//Define os lados da colisao com o mundo
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
	//Colisao entre dois objetos
	static bool Colided(GameObject * obj1, GameObject * obj2);
	//"Colisao" com as bordas do mundo
	//Retorna um array de tamanho 4 com as colisoes para cada lado
	static bool * Colided(GameObject * obj, glm::vec2 worldSize);
};

#endif