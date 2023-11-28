#include "HouseModel.h"
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h> 
#include <SOIL/SOIL.h>
#include <iostream>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags
#include <vector>
using namespace std;
using namespace ModelsHeaders;

Model* HouseModel::setTheShape() {
    Assimp::Importer importer;
    unsigned int importOptions = aiProcess_Triangulate
        | aiProcess_OptimizeMeshes              // sloučení malých plošek
        | aiProcess_JoinIdenticalVertices       // NUTNÉ jinak hodně duplikuje
        | aiProcess_Triangulate                 // prevod vsech ploch na trojuhelniky
        | aiProcess_CalcTangentSpace;           // vypocet tangenty, nutny pro spravne pouziti normalove mapy
    const aiScene* scene = importer.ReadFile("model.obj", importOptions);
    vector<float> data;
    if (scene) {
        aiMesh* mesh = scene->mMeshes[0];
        this->count = mesh->mNumFaces * 3;
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            for (unsigned int j = 0; j < 3; j++)
            {
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].z);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].z);
                data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].y);
            }
        }
    }
    //Vertex Array Object (VAO)
    GLuint VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

    GLuint VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //enable vertex attributes
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float) * 3));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float) * 6));
    glActiveTexture(GL_TEXTURE0);
    GLuint image = SOIL_load_OGL_texture("model.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (image == NULL) {
        std::cout << "An error occurred while loading image." << std::endl;
        exit(EXIT_FAILURE);
    }
    glBindTexture(GL_TEXTURE_2D, image);

    return this;
}
void HouseModel::drawTheShape() {
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, this->count); //mode,first,count

}
