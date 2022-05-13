#include "Shader.h"
#include <GL/glew.h>
#include <iostream>
#include <string>


Shader::Shader(std::string vertexSource, std::string fragmentSource)
{
	shaderId = glCreateProgram();

	unsigned int vertexShd = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
	unsigned int fragShd = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

	glAttachShader(shaderId, vertexShd);
	glAttachShader(shaderId, fragShd);

	glLinkProgram(shaderId);
	glValidateProgram(shaderId);
	GLint p;
	glGetProgramiv(shaderId,GL_VALIDATE_STATUS, &p);

	if (p == GL_TRUE) {
		std::cout << "Validated Shader Successfully" << "\n";
	}
	else
	{
		std::cout << "Shader Validation Failed" << "\n";
	}
	

	glDeleteShader(vertexShd);
	glDeleteShader(fragShd);
}

Shader::~Shader()
{
	glDeleteProgram(shaderId);
	
}


unsigned int Shader::compileShader(std::string source, unsigned int type)
{
	const char* c = source.c_str();
	unsigned int shd = glCreateShader(type);
	glShaderSource(shd, 1, &c, nullptr);
	glCompileShader(shd);

	int result;
	glGetShaderiv(shd, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(shd, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));

		glGetShaderInfoLog(shd, length, &length, message);
		std::cout << "Shader Compilation Failed\n";
		std::cout << message << "\n";

		glDeleteShader(shd);
		return 0;
	}

	return shd;
}


unsigned int Shader::getId()
{
	return shaderId;
}

void Shader::bind()
{
	glUseProgram(shaderId);
}

void Shader::unbind()
{
	glUseProgram(0);
}