#pragma once
#include "ShaderLoader.h"
namespace ShaderHeaders {
	class Shader : public ShaderLoader
	{
	public:
		Shader();
		~Shader();
		Shader* setVertexShader(const char* vertexShaderSource);
		Shader* setFragmentShader(const char* fragmentShaderSource);
		unsigned int getShaderProgram();
		Shader* linkShaders();
	private:
		unsigned int fragShader;
		unsigned int vertexShader;
		unsigned int shaderProgram;
	};

}

