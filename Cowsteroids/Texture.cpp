#include "Texture.h"

#include <iostream>
using namespace std;

#include <GL\glew.h>
#include <SOIL.h>

Texture::Texture(bool hasAlpha)
{
	//Cria o "nome" da textura
	glGenTextures(1, &this->ID);

	if (hasAlpha)
	{
		this->internalFormat = GL_RGBA;
		this->imageFormat = GL_RGBA;
	}
	else
	{
		this->internalFormat = GL_RGB;
		this->imageFormat = GL_RGB;
	}

	this->wrapS = GL_REPEAT;
	this->wrapT = GL_REPEAT;
	this->filterMin = GL_LINEAR;
	this->filterMax = GL_LINEAR;
}

Texture::~Texture()
{

}

void Texture::Generate(int width, int height, unsigned char * data)
{
	this->width = width;
	this->height = height;

	//Ativa a textura
	glBindTexture(GL_TEXTURE_2D, this->ID);
	//Especifica uma imagem como textura
	glTexImage2D(GL_TEXTURE_2D, 0, this->imageFormat, width, height, 0, this->internalFormat, GL_UNSIGNED_BYTE, data);

	//Define parametros da textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMax);

	//Desativa a textura
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Use() const
{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}
