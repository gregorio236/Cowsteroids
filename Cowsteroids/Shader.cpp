#include "Shader.h"

#include <iostream>
using namespace std;

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
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const char * vertSource, const char * fragSource)
{
	unsigned int vertID, fragID;

	vertID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertID, 1, &vertSource, NULL);
	glCompileShader(vertID);
	checkCompileErrors(vertID, "VERTEX");

	fragID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragID, 1, &fragSource, NULL);
	glCompileShader(fragID);
	checkCompileErrors(fragID, "FRAGMENT");

	this->ID = glCreateProgram();
	glAttachShader(this->ID, vertID);
	glAttachShader(this->ID, fragID);
	glLinkProgram(this->ID);
	checkCompileErrors(this->ID, "PROGRAM");

	glDeleteShader(vertID);
	glDeleteShader(fragID);
}

void Shader::SetUniform(const char * name, int &value)
{
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetUniform(const char * name, float &value)
{
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetUniform(const char * name, vec3 &value)
{
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::SetUniform(const char * name, mat4 &value)
{
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, value_ptr(value));
}

void Shader::checkCompileErrors(unsigned int shader, const char * type)
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << endl << infoLog << endl << "=====/-/=====/=====/-/=====/=====/-/=====" << endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << endl << infoLog << endl << "=====/-/=====/=====/-/=====/=====/-/=====" << endl;
		}
	}
}
