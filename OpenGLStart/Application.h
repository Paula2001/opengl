#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Application
{
public:
	Application* setVersion();
	Application* setWindow(int width, int height,const char* title);

	void initRenderLoop();
private:
		GLFWwindow* window;
};

