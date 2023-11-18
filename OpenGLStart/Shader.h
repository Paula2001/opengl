#pragma once
#include "ShaderLoader.h"
#include <glm/gtc/type_ptr.hpp>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

using namespace glm;
namespace ShaderHeaders {
	class Shader : public ShaderLoader
	{
	public:
		Shader();
		~Shader();
		Shader* setVertexShader(const char* vertexShaderSource);
		Shader* setFragmentShader(const char* fragmentShaderSource);
		unsigned int getShaderProgram();
		void setLightPos(vec3 pos);
		Shader* linkShaders();
	private:
		unsigned int fragShader;
		unsigned int vertexShader;
		unsigned int shaderProgram;
	};

}

