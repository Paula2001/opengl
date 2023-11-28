#version 330
in vec4 worldPos;
in vec3 worldNorm;
out vec4 fragColor;
uniform vec4 objColor;
uniform vec3 camPosition; // Assuming you have a camera position
uniform vec3 lightPos; // Assuming you have a light position
void main(void) {
vec3 fragPosition = worldPos.xyz / worldPos.w;
vec3 lightVector = normalize(lightPos - fragPosition);
vec3 camVector = normalize(camPosition - fragPosition);
vec3 halfVector = normalize(lightVector + camVector);
vec3 reflectVector = normalize(reflect(-lightVector, worldNorm));
float diff = max(dot(normalize(lightVector), normalize(worldNorm)), 0.0);
float shine = 32.0;
float blinn = pow(max(dot(worldNorm,halfVector), 0.0), shine);
float spec = pow(max(dot(reflectVector, camVector), 0.0), shine);
vec4 specular = vec4(1.0, 1.0, 1.0, 1.0) * spec;

vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0); 
vec4 diffuse = vec4(0.385, 0.647, 0.812, 1.0) * diff;
//fragColor = specular;
fragColor =  (ambient + diffuse + specular) * objColor;
}