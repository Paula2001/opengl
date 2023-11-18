#version 330
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 camMatrix;
out vec3 vertexColor;
layout(location=0) in vec3 vp;
layout(location=1) in vec3 vn;
void main () {
     vertexColor=vn;
     gl_Position =  view * camMatrix * vec4(vp, 1.0);
};
