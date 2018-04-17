#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>

#include "Shader.h"
#include "Texture.h"

class ResourceManager
{
public:
	static Shader& LoadShader(const char* vertFile, const char* fragFile, const char* name);
	static Shader& GetShader(const char* name);

	static Texture& LoadTexture(const char* file, bool hasAlpha, const char* name);
	static Texture& GetTexture(const char* name);

	static void Clear();

private:
	static std::map<const char*, Shader> shaders;
	static std::map<const char*, Texture> textures;

	static Shader& loadShaderFromFile(const char* vertFile, const char* fragFile);
	static Texture& loadTextureFromFile(const char* file, bool hasAlpha);
};

#endif