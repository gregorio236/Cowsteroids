#ifndef SHADER_H
#define SHADER_H

#include <glm\glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	//Ativa o shader com glUseProgram
	Shader& Use();

	//Compila o shader com os codigos do vertex e fragment
	void Compile(const char* vertSource, const char* fragSource);

	//Atribui o valor de um uniform int
	void SetUniform(const char* name, int value) const;
	//Atribui o valor de um uniform float
	void SetUniform(const char* name, float value) const;
	//Atribui o valor de um uniform vec3
	void SetUniform(const char* name, glm::vec3 &value) const;
	//Atribui o valor de um uniform mat4
	void SetUniform(const char* name, glm::mat4 &value) const;

	void Clear();

private:
	unsigned int ID;

	//Checa erros durante a compilacao
	void checkCompileErrors(unsigned int shader, const char* type) const;
};

#endif