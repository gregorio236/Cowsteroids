#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <vector>
#include <string>

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
	static Shader LoadShader(const char* vertFile, const char* fragFile, const char* name);
	//Pega um shader pelo nome
	static Shader GetShader(const char* name);

	//Carrega uma textura dado o caminho da imagem
	static Texture LoadTexture(const char* file, bool hasAlpha, const char* name);
	//Pega uma textura pelo nome
	static Texture GetTexture(const char* name);

	static std::vector<Score> GetScoreBoard(const char* path);
	static void SetScoreBoard(const char* path, std::vector<Score> scoreboard);

	static void Clear();

private:
	static std::map<const char*, Shader> shaders;
	static std::map<const char*, Texture> textures;

	static Shader loadShaderFromFile(const char* vertFile, const char* fragFile);
	static Texture loadTextureFromFile(const char* file, bool hasAlpha);
};

#endif