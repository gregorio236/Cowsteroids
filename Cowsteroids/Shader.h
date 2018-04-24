#ifndef SHADER_H
#define SHADER_H

#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>

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
	void SetUniform(const char* name, const glm::vec3 &value) const;
	//Atribui o valor de um uniform mat4
	void SetUniform(const char* name, const glm::mat4 &value) const;

	//Deleta esse shader da memoria do opengl
	void Clear();

private:
	//ID do shader no opengl
	unsigned int ID;

	//Checa erros durante a compilacao
	void checkCompileErrors(unsigned int shader, const char* type) const;
};

#endif