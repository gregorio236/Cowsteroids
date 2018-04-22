#include "Shader.h"

#include <iostream>

#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>

Shader::Shader()
{

}

Shader::~Shader()
{

}

Shader& Shader::Use()
{
	//Ativa o shader program para ser utilizado
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const char * vertSource, const char * fragSource)
{
	unsigned int vertID, fragID;

	//Cria o shader object e retorna um "ponteiro"
	vertID = glCreateShader(GL_VERTEX_SHADER);
	//Coloca o codigo no shader
	glShaderSource(vertID, 1, &vertSource, NULL);
	//Compila o shader
	glCompileShader(vertID);
	//Checa erros de compilacao do shader
	checkCompileErrors(vertID, "VERTEX");

	//A mesma coisa que o anterior, so que fragment
	fragID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragID, 1, &fragSource, NULL);
	glCompileShader(fragID);
	checkCompileErrors(fragID, "FRAGMENT");

	//Cria o program object e retorna o "ponteiro" para ele
	this->ID = glCreateProgram();
	//Fixa os shaders no program
	glAttachShader(this->ID, vertID);
	glAttachShader(this->ID, fragID);
	//Cria os executaveis dos shaders
	glLinkProgram(this->ID);
	//Checa erros
	checkCompileErrors(this->ID, "PROGRAM");

	//Marca os shaders para serem deletados quando o program for deletado
	glDeleteShader(vertID);
	glDeleteShader(fragID);
}

void Shader::SetUniform(const char * name, int value) const
{
	//Primeiro encontra o local onde esta o uniform
	//Depois troca o valor dele para value
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetUniform(const char * name, float value) const
{
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetUniform(const char * name, const glm::vec3 &value) const
{
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::SetUniform(const char * name, const glm::mat4 &value) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, value_ptr(value));
}

void Shader::Clear()
{
	//Deleta o shader prorgam da memoria do opengl
	glDeleteProgram(this->ID);
}

void Shader::checkCompileErrors(unsigned int shader, const char * type) const
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		//Teste para ver se o shader compilou
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			//Se nao, pega as informacoes e escreve no console
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << std::endl << infoLog << "\n=====/-/=====/=====/-/=====/=====/-/=====\n";
		}
	}
	else
	{
		//Mesma coisa, mas para o shader program
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << std::endl << infoLog << "\n=====/-/=====/=====/-/=====/=====/-/=====\n";
		}
	}
}
