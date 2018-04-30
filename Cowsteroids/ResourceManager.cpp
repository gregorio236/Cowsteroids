#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "GL\glew.h"
#include <SOIL.h>

std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture> ResourceManager::textures;

Shader ResourceManager::LoadShader(std::string vertFile, std::string fragFile, std::string name)
{
	shaders[name] = loadShaderFromFile(vertFile, fragFile);
	return shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
	return shaders[name];
}

Texture ResourceManager::LoadTexture(std::string file, bool hasAlpha, std::string name)
{
	textures[name] = loadTextureFromFile(file, hasAlpha);
	return textures[name];
}

Texture ResourceManager::GetTexture(std::string name)
{
	return textures[name];
}

std::vector<Score> ResourceManager::GetScoreBoard(std::string path)
{
	std::vector<Score> scoreboard;

	std::fstream file;
	file.open(path, std::ios::in | std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Failed to open scoreboard file\n";
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			char a, b, c;
			int score;

			file.read((char*)&a, sizeof(char));
			file.read((char*)&b, sizeof(char));
			file.read((char*)&c, sizeof(char));
			file.read((char*)&score, sizeof(int));

			std::stringstream name;
			name << a << b << c;

			Score s;
			s.name = name.str();
			s.score = score;

			scoreboard.push_back(s);
		}
	}

	file.close();

	return scoreboard;
}

void ResourceManager::SetScoreBoard(std::string path, std::vector<Score> scoreboard)
{
	std::fstream file;
	file.open(path, std::ios::out | std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Failed to open scoreboard file\n";
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			const char * name = scoreboard[i].name.c_str();
			int score = scoreboard[i].score;

			file.write((char*)name, 3 * sizeof(char));
			file.write((char*)&score, sizeof(int));
		}
	}

	file.close();
}

Configuration ResourceManager::LoadConfiguration(std::string path)
{
	std::ifstream file;
	file.open(path);

	std::vector<std::string> lines;
	std::string s;

	while (std::getline(file, s))
	{
		lines.push_back(s);
	}

	return Configuration(lines);
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

Shader ResourceManager::loadShaderFromFile(std::string vertFile, std::string fragFile)
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

Texture ResourceManager::loadTextureFromFile(std::string file, bool hasAlpha)
{
	Texture texture(hasAlpha);
	int width, height;
	unsigned char* image = SOIL_load_image(file.c_str(), &width, &height, 0, hasAlpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
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
