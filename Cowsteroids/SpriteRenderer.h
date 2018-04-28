#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>

#include "Shader.h"
#include "Texture.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();

	//Desenha a sprite
	void DrawSprite(Texture &texture, glm::vec2 pos, glm::vec2 size, float z, float offset = 0.0f,
		int frameCount = 1,	float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));

private:
	unsigned int VAO;
	Shader shader;

	//Inicializa o VAO
	void initialize();
};

#endif