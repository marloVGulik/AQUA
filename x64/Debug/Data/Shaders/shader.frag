#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 posWorldspace;
in vec3 normalCamspace;
in vec3 eyeDirectionCamspace;
in vec3 dirLightCamspace;

// Ouput data
out vec3 color;


uniform sampler2D textureSampler;
uniform mat4 MV;

void main(){
	vec3 diffuseColor = texture(textureSampler, UV).rgb;
	vec3 ambientColor = diffuseColor * vec3(0.1, 0.1, 0.1);
	vec3 specularColor = vec3(0.3, 0.3, 0.3);

	vec3 lightColor = vec3(1, 1, 1);
	float lightPower = 2.0;
	float distance = length(dirLightCamspace - posWorldspace);

	vec3 n = normalize(normalCamspace);
	vec3 l = normalize(dirLightCamspace);

	float cosTheta = clamp(dot(n, vec3(1, 1, 1)), 0, 1);

	vec3 E = normalize(eyeDirectionCamspace);
	vec3 R = reflect(vec3(-1, -1, -1), n);

	float cosAlpha =  clamp(dot(E, R), 0, 1);
	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
  	color = ambientColor * cosTheta + diffuseColor * lightColor * lightPower / (distance * distance) * cosTheta / (distance * distance) /*+ specularColor * lightColor * lightPower * pow(cosAlpha, 5) / (distance * distance)*/;
	// color = vec3(1.0, 1.0, 1.0);
}