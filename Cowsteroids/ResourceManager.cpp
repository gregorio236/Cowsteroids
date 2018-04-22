#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "GL\glew.h"
#include <SOIL.h>

std::map<const char*, Shader> ResourceManager::shaders;
std::map<const char*, Texture> ResourceManager::textures;

Shader ResourceManager::LoadShader(const char * vertFile, const char * fragFile, const char * name)
{
	shaders[name] = loadShaderFromFile(vertFile, fragFile);
	return shaders[name];
}

Shader ResourceManager::GetShader(const char * name)
{
	return shaders[name];
}

Texture ResourceManager::LoadTexture(const char * file, bool hasAlpha, const char * name)
{
	textures[name] = loadTextureFromFile(file, hasAlpha);
	return textures[name];
}

Texture ResourceManager::GetTexture(const char * name)
{
	return textures[name];
}

void ResourceManager::Clear()
{
	for (auto s : shaders)
	{
		s.second.Clear();
	}
	for (auto t : textures)
	{
		t.second.Clear();
	}
}

Shader ResourceManager::loadShaderFromFile(const char * vertFile, const char * fragFile)
{
	std::string vertCode;
	std::string fragCode;

	try
	{
		std::ifstream vertShaderFile, fragShaderFile;
		vertShaderFile.open(vertFile);
		fragShaderFile.open(fragFile);

		std::stringstream vertStream, fragStream;

		vertStream << vertShaderFile.rdbuf();
		fragStream << fragShaderFile.rdbuf();

		vertShaderFile.close();
		fragShaderFile.close();

		vertCode = vertStream.str();
		fragCode = fragStream.str();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files\n";
	}

	const char* vertShaderCode = vertCode.c_str();
	const char* fragShaderCode = fragCode.c_str();

	Shader shader;
	shader.Compile(vertShaderCode, fragShaderCode);
	return shader;
}

Texture ResourceManager::loadTextureFromFile(const char * file, bool hasAlpha)
{
	Texture texture(hasAlpha);
	int width, height;
	unsigned char* image = SOIL_load_image(file, &width, &height, 0, hasAlpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	if (image)
	{
		texture.Generate(width, height, image);
	}
	else
	{
		std::cout << "ERROR::TEXTURE: Failed to read image file\n";
	}
	SOIL_free_image_data(image);

	return texture;
}
