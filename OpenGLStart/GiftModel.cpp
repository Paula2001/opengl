#include "GiftModel.h"
#include <GL/glew.h>
#include "gift.h"
using namespace ModelsHeaders;
Model* GiftModel::setTheShape() {
    GLuint VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gift), gift,
        GL_STATIC_DRAW);
    //vertex attribute object(VAO)
    VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    glEnableVertexAttribArray(0); //enable vertex attributes
    glEnableVertexAttribArray(1); //enable vertex attributes
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    return this;
}
void GiftModel::drawTheShape() {

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 66624);
}