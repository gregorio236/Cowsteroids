#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glm\glm.hpp>

#include "Shader.h"
#include "Texture.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();

	//Desenha a sprite
	void DrawSprite(Texture &texture, glm::vec2 pos, glm::vec2 size,
		float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));

private:
	unsigned int VAO;
	Shader shader;

	//Inicializa o VAO
	void initialize();
};

#endif