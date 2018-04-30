#include "SpriteRenderer.h"

#include <GL\glew.h>
#include <glm\mat4x4.hpp>
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

void SpriteRenderer::DrawSprite(Texture & texture, glm::vec2 pos, glm::vec2 size, float z, float offset, int frameCount, float rotation, glm::vec3 color)
{
	//Matriz modelo da sprite
	glm::mat4 model = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	//Primeiro se escala, depois se rotaciona e por ultimo se translada a matriz
	//Mas como é multiplicado, é feio ao contrario

	//Translacao para a posicao
	model = glm::translate(model, glm::vec3(pos, 0.0f));

	//Primeiro leva o centro da imagem para o centro ortografico
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	//Paara depois rotacionar
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	//E depois voltar para a posicao original
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	//Escalonamento do modelo
	model = glm::scale(model, glm::vec3(size, 1.0f));

	//Ativa o shader e define os uniforms
	this->shader.Use().SetUniform("model", model);
	this->shader.SetUniform("spriteColor", color);
	this->shader.SetUniform("layer", z);
	this->shader.SetUniform("offset", offset);
	this->shader.SetUniform("frameCount", frameCount);

	//Ativa a textura
	glActiveTexture(GL_TEXTURE0);
	texture.Use();

	//Ativa o VAO
	glBindVertexArray(this->VAO);
	//Desenha os dois triangulos
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//Desativa o VAO
	glBindVertexArray(0);
}

void SpriteRenderer::initialize()
{
	//Dois triangulos
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
