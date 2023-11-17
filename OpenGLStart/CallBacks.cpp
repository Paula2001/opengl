#include "CallBacks.h"

void CallBacks::glfwErrorCallback(int error, const char* description) {
	cout << "Error : " << description << endl;
	throw("glfw error");
}