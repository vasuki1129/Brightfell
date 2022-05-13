#pragma once
#include <string>

const std::string vertexShaderSource =
"#version 330 core\n"
"\n"
"layout(location = 1) in vec4 position;\n"
"layout(location = 2) in vec2 aTexCoord;\n"
"out vec4 pos;\n"
"out vec2 TexCoord;\n"
"\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main() {\n"
"	gl_Position = projection * view * model * position;\n"
"	pos = position;\n"
"	TexCoord = aTexCoord;\n"
"\n"
"}\n"
;

const std::string fragmentShaderSource =
"#version 330 core\n"
"\n"
"uniform vec4 col;\n"
"in vec4 pos;\n"
"in vec2 TexCoord;"
"out vec4 color;\n"
"uniform sampler2D textureData;\n"
"\n"
"\n"
"void main() {\n"
"	color = texture(textureData,TexCoord);\n"
"}\n"
;






struct Shader
{
private:
	unsigned short DEBUG = 0;
	unsigned int shaderId;

	unsigned int compileShader(std::string source, unsigned int type);

public:
	unsigned int getId();

	Shader(std::string vertexSource, std::string fragmentSource);
	~Shader();

	void bind();
	void unbind();

};

