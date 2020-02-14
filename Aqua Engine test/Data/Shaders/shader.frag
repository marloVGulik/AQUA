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
	float lightPower = 40;
	float distance = length(dirLightCamspace - posWorldspace);

	vec3 n = normalize(normalCamspace);
	vec3 l = normalize(dirLightCamspace);

	float cosTheta = clamp(dot(n, vec3(1)), 0, 1);

	vec3 E = normalize(eyeDirectionCamspace);
	vec3 R = reflect(vec3(-1, -1, -1), n);

	float cosAlpha =  clamp(dot(E, R), 0, 1);
	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
	float costhetaCalc = lightPower * cosTheta / (distance * distance);
	float costhetaOut = 0;
	if(costhetaCalc < 0.2) {
		costhetaOut = 0.2;
	} else if(costhetaCalc < 0.8 && 0.2 < costhetaCalc) {
		costhetaOut = 0.5;
	} else {
		costhetaOut = 1.0;
	}

	float cosAlphaOut;
	vec3 lightedColor = (diffuseColor - ambientColor) * lightColor * costhetaOut;
  	color = ambientColor + lightedColor;
	// color = vec3(costhetaCalc);
	// color = ambientColor + (diffuseColor - ambientColor) * (lightColor * lightPower);
	// color = vec3(1.0, 1.0, 1.0);
}