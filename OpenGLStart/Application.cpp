#include <GL/glew.h>
#include "Camera.h";
#include "Application.h"
#include <iostream>
#include "MultiObjectsScene.h"
#include "PhongScene.h"
#include "SkyBoxScene.h"
#include "Light.h"
using namespace std;
using namespace ScenesHeaders;
void error_callback(int error, const char* description)
{
	cout << "Error : " << description << endl;
	throw runtime_error("GLFW error");
}

void cursor_callback(GLFWwindow* window, double x, double y) {
    printf("cursor_callback x:%f y:%f \n", x, y);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    std::cout << "Scrolling: X Offset=" << xoffset << " Y Offset=" << yoffset << std::endl;
}


Application* Application::setVersion() {
	glfwInit();
	glfwSetErrorCallback(error_callback);
	return this;
}

Application* Application::setWindow(int width, int height,const char* title) {

	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(this->window);
    glewExperimental = GL_TRUE;
    glewInit();
    glEnable(GL_DEPTH_TEST); //Z-buffer
    glViewport(0, 0, width, height);
    glfwSetCursorPosCallback(this->window, cursor_callback);
    glfwSwapInterval(1);
    glfwSetScrollCallback(this->window, scroll_callback);
	return this;
}

void Application::initRenderLoop() {
    Camera* c = new Camera(800, 800, glm::vec3(1.0f, 1.0f, 10.0f));

    Light* light = new Light(glm::vec3(0.0f, 0.0f, 0.0f), // Position
        glm::vec3(1.0, 0.1, 1.0)); // Color

    auto x = (new SkyBoxScene())
        ->ComposeScene()
        ->setLight(light)
        ->setCamera(c);
    
    while (!glfwWindowShouldClose(this->window)) {
        // TODO: Add Input in here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);

        x->init(this->window);
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    glfwTerminate();
}