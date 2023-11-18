#include <GL/glew.h>
#include "Camera.h";
#include "Application.h"
#include <iostream>
#include "SkyScene.h"
#include "PhongScene.h"
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetErrorCallback(error_callback);
	return this;
}

Application* Application::setWindow(int width, int height,const char* title) {
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(this->window);
    glewInit();
    glEnable(GL_DEPTH_TEST); //Z-buffer
    glfwSetCursorPosCallback(this->window, cursor_callback);
    glfwSetScrollCallback(this->window, scroll_callback);
	return this;
}

void Application::initRenderLoop() {
    Camera* c = new Camera(800, 800, glm::vec3(1.0f, 1.0f, 10.0f));
    auto x = (new SkyScene())->ComposeScene()->setCamera(c);
    //auto x = (new PhongScene())->ComposeScene()->setCamera(c);
    while (!glfwWindowShouldClose(this->window)) {
        // TODO: Add Input in here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render this init color of the background
        glClearColor(1.2f, 0.3f, 0.3f, 0.0f);

        x->init(this->window);
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