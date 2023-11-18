#version 330
layout(location = 0) in vec3 vp; // position
layout(location = 1) in vec3 vn; // normal
out vec4 worldPos;
out vec3 worldNorm;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
void main(void) {
    worldPos = modelMatrix * vec4(vp, 1.0);
    worldNorm = mat3(transpose(inverse(modelMatrix))) * vn;
    gl_Position = vec4(vp, 1.0);
};