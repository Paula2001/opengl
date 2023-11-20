#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Application.h"

int main() {
    (new Application())->setVersion()->setWindow(800, 800, "this is a test")->initRenderLoop();
    return 0;
}
