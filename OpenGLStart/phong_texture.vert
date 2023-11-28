#version 330
layout(location = 0) in vec3 vp; // position
layout(location = 1) in vec3 vn; // normal
out vec4 worldPos;
out vec3 worldNorm;
uniform mat4 camMatrix;
uniform mat4 view;
uniform mat4 projectionMatrix;
void main(void) {
    worldPos = view * vec4(vp, 1.0);
    worldNorm = mat3(transpose(inverse(view))) * vn;
    gl_Position = camMatrix *  view * vec4(vp, 1.0);
}