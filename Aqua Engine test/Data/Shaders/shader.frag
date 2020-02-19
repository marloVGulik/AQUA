#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 dirLightCamSpace;
in vec3 posWorldspace;
in vec3 normalCamspace;
in vec3 eyeDirectionCamspace;

// Outline
vec3 outlineColor = vec3(0.0);
float thickness = 1.0;

// Ouput data
out vec4 color;

const float outlineOffset = 1.0 / 256.0;

uniform sampler2D textureSampler;
uniform mat4 MV;
uniform float outlineTreshold = 0.5;


void main(){
	// vec4 diffuseColor = vec4(texture(textureSampler, UV).rgb, 1.0);
	vec4 diffuseColor = texture(textureSampler, UV);
	vec4 ambientColor = diffuseColor * vec4(0.1, 0.1, 0.1, 1.0);
	vec4 specularColor = vec4(0.3, 0.3, 0.3, 1.0);

	vec3 lightColor = vec3(1.0);
	float lightPower = 40.0f;
	float distance = length(dirLightCamSpace - posWorldspace);


	vec3 n = normalize(normalCamspace);
	vec3 l = vec3(normalize(dirLightCamSpace));

	float cosTheta = clamp(dot(n, l), 0.0, 1.0);

	vec3 E = normalize(eyeDirectionCamspace);
	vec3 R = reflect(-l, n);

	float cosAlpha =  clamp(dot(E, R), 0.0, 1.0);
	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
	float costhetaCalc = lightPower * cosTheta / (distance * distance);
	float costhetaOut = 0.0;
	if(costhetaCalc < 0.2) {
		costhetaOut = 0.2;
	} else if(costhetaCalc < 0.8 && 0.2 < costhetaCalc) {
		costhetaOut = 0.5;
	} else {
		costhetaOut = 1.0;
	}

	float cosAlphaOut;
	vec4 lightedColor = (diffuseColor - ambientColor) * costhetaCalc * vec4(lightColor, 0.5);
	color = ambientColor + lightedColor;
	// color = vec4(color.a);

	color = vec4(costhetaCalc);
	// color = ambientColor + (diffuseColor - ambientColor) * (lightColor * lightPower);
	// color = vec3(1.0, 1.0, 1.0);
}