#version 450
layout(location = 0) in vec3 vp;
out vec4 worldPos;
out vec3 worldNorm;
uniform mat4 view;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 fragmentLocalPosition;

uniform mat4 camMatrix;
void main () {
	worldPos = view * vec4(vp, 1.0);
    worldNorm = mat3(transpose(inverse(view))) * vn;
    gl_Position = camMatrix *  view  modelMatrix * vec4(vp, 1.0);
	 
	 fragmentLocalPosition = vp;


}
