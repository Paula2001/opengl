#version 330
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 vc;
layout(location = 2) in vec2 uv; 
uniform mat4 modelMatrix;
out vec2 uvc;
out vec4 worldPos;
out vec3 worldNorm;
uniform mat4 camMatrix;
uniform mat4 view;

void main () {
    worldPos = view * vec4(vp, 1.0);
    worldNorm = mat3(transpose(inverse(view))) * vc;
    gl_Position = camMatrix *  view *   vec4 (vp, 1.0);
    uvc=uv;
};