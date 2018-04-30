#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <vector>
#include <string>

#include "Configuration.h"
#include "Shader.h"
#include "Texture.h"

struct Score
{
	std::string name;
	int score;
};

class ResourceManager
{
public:
	//Carrega um shader dado os caminhos dos arquivos
	static Shader LoadShader(std::string vertFile, std::string fragFile, std::string name);
	//Pega um shader pelo nome
	static Shader GetShader(std::string name);

	//Carrega uma textura dado o caminho da imagem
	static Texture LoadTexture(std::string file, bool hasAlpha, std::string name);
	//Pega uma textura pelo nome
	static Texture GetTexture(std::string name);

	static std::vector<Score> GetScoreBoard(std::string path);
	static void SetScoreBoard(std::string path, std::vector<Score> scoreboard);

	static Configuration LoadConfiguration(std::string path);

	static void Clear();

private:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;

	static Shader loadShaderFromFile(std::string vertFile, std::string fragFile);
	static Texture loadTextureFromFile(std::string file, bool hasAlpha);
};

#endif