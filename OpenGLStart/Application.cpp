#include <GL/glew.h>
#include "Application.h"
#include <iostream>
#include "SkyScene.h"
using namespace std;

void error_callback(int error, const char* description)
{
	cout << "Error : " << description << endl;
	throw runtime_error("GLFW error");
}

Application* Application::setVersion() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetErrorCallback(error_callback);
	return this;
}

Application* Application::setWindow(int width, int height,const char* title) {
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
    glewInit();
    glEnable(GL_DEPTH_TEST); //Z-buffer
	return this;
}

void Application::initRenderLoop() {
    auto x = (new SkyScene())->ComposeScene();
    
    while (!glfwWindowShouldClose(this->window)) {
        // TODO: Add Input in here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render this init color of the background
        glClearColor(1.2f, 0.3f, 0.3f, 0.0f);

        x->init();
        // TODO: all the dynamic stuff in here

        // TODO: all the dynamic stuff in here
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    // TODO: clean
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}