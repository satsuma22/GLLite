#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <gtc/type_ptr.hpp>

Shader::Shader()
	: m_ID(0)
{
}

Shader::Shader(Shader&& other) noexcept
{
	m_ID = other.m_ID;
	other.m_ID = 0;
}

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader)
	: m_VSFilePath(vertexShader), m_FSFilePath(fragmentShader), m_ID(0)
{
	ShaderProgramSource source = ParseShader();
	m_ID = CreateShader(source.VertexSource, source.FragmentSource);
	Bind();
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

Shader& Shader::operator=(Shader&& other) noexcept
{
	if (this != &other)
	{
		m_ID = other.m_ID;
		other.m_ID = 0;
	}

	return *this;
}

void Shader::Bind() const
{
	glUseProgram(m_ID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::SetUniform1i(const std::string& name, int v) 
{
	Bind();
	int location = GetUniformLocation(name);
	glUniform1i(location, v);
	Unbind();
}

void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2) 
{
	Bind();
	int location = GetUniformLocation(name);
	glUniform3f(location, v0, v1, v2);
	Unbind();
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	Bind();
	int location = GetUniformLocation(name);
	glUniform4f(location, v0, v1, v2, v3);
	Unbind();
}

void Shader::SetUniformMat4f(const std::string& name, glm::mat4& mat)
{
	Bind();
	int location = GetUniformLocation(name);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	Unbind();
}

ShaderProgramSource Shader::ParseShader() const
{
	std::string line;
	std::stringstream VS;

	std::fstream VSFile;

	for (auto& directory : ShaderDirectories)
	{
		VSFile.open(directory + m_VSFilePath);
		std::cout << "Trying to open " << directory + m_VSFilePath << std::endl;
		if (VSFile.is_open()) break;
	}

	if (!VSFile.is_open())
	{
		std::cout << "Could not find Shader Source in " << m_VSFilePath << std::endl;
		//std::cin.get();
		exit(-1);
	}


	while (getline(VSFile, line))
	{
		VS << line << "\n";
	}

	VSFile.close();

	std::stringstream FS;
	std::fstream FSFile;

	for (auto& directory : ShaderDirectories)
	{
		FSFile.open(directory + m_FSFilePath);

		if (FSFile.is_open()) break;
	}

	if (!FSFile.is_open())
	{
		std::cout << "Could not find Shader Source in " << m_FSFilePath << std::endl;
		std::cin.get();
		exit(-1);
	}

	while (getline(FSFile, line))
	{
		FS << line << "\n";
	}

	FSFile.close();

	return { VS.str(), FS.str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* sourceString = source.c_str();
	glShaderSource(id, 1, &sourceString, NULL);
	glCompileShader(id);

	int  success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << ((type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	char infoLog[512];
	int success;

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
	}

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int Shader::GetUniformLocation(const std::string& name) const
{
	int location = glGetUniformLocation(m_ID, name.c_str());

	if (location == -1)
		std::cout << "Uniform '" << name << "' not found.\n";

	return location;
}

std::vector<std::string> Shader::ShaderDirectories = {};