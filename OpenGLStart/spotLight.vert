#version 330
uniform mat4 view;
uniform mat4 projectMatrix;
uniform mat4 spotLightSize;
uniform mat4 camMatrix;
out vec3 worldNormal;
out vec3 worldPosition;
layout(location=0) in vec3 vp;
layout(location=1) in vec3 vn;
void main () {
   worldNormal = transpose(inverse(mat3(view))) * vn;
   vec4 position = view * vec4(vp, 1.0); 
   worldPosition =  position.xyz / position.w;
   gl_Position = spotLightSize  * vec4(vp, 1.0);
};