#include "SpriteRenderer.h"

#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>

SpriteRenderer::SpriteRenderer(Shader & shader)
{
	this->shader = shader;
	this->initialize();
}

SpriteRenderer::~SpriteRenderer()
{
	//Deleta o VAO
	glDeleteVertexArrays(1, &this->VAO);
}

void SpriteRenderer::DrawSprite(Texture & texture, glm::vec2 pos, glm::vec2 size, float rotation, glm::vec3 color)
{

}

void SpriteRenderer::initialize()
{
	float vertices[] = {
		//Pos       //Textura
		0.0f, 1.0f,  0.0f, 1.0f, //esq-cima
		1.0f, 0.0f,  1.0f, 0.0f, //dir-baixo
		0.0f, 0.0f,  0.0f, 0.0f, //esq-baixo

		0.0f, 1.0f,  0.0f, 1.0f, //esq-cima
		1.0f, 1.0f,  1.0f, 1.0f, //dir-cima
		1.0f, 0.0f,  1.0f, 0.0f  //dir-baixo
	};

	unsigned int VBO;

	//Cria o VAO e o VBO
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	//Ativa o VAO
	glBindVertexArray(VAO);

	//Ativa o VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Aloca memoria para o VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Define o atributo para o shader
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	//Ativa o atributo
	glEnableVertexAttribArray(0);

	//Desativa o VAO
	glBindVertexArray(0);

	//Deleta o VBO
	glDeleteBuffers(1, &VBO);
}
