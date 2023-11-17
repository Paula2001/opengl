#pragma once
#include <iostream>
using namespace std;
static void glfwErrorCallback(int error, const char* description) {
	cout << "Error : " << description << endl;
	throw("glfw error");
};

static void glfwCloseWindowCallback(GLFWwindow* window) {

}