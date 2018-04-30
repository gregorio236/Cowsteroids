#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>

#include "Configuration.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "Texture.h"

class GameObject
{
public:
	GameObject(glm::vec2 pos, Texture sprite, float rotation, Configuration config);
	~GameObject();

	float GetRotation();
	glm::vec2 GetPos();
	void SetPos(glm::vec2 pos);
	glm::vec2 GetSize();
	//retorna o centro do circulo de colisao, o "centro de massa"
	glm::vec2 GetCOM();
	//retorna o raio do circulo de colisao
	float GetRadius();

	void Draw(SpriteRenderer &renderer, float z, float dt);

	virtual void Update(float dt);

protected:
	glm::vec2 position;
	glm::vec2 size;
	glm::vec3 color;
	float rotation;
	float speed;

	Sprite sprite;

	//centro do circulo de colisao, o "centro de massa"
	glm::vec2 COM;
	//raio do circulo de colisao
	float radius;
};

#endif