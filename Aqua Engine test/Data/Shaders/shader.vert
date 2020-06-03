#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPositionModelspace;
layout(location = 1) in vec2 vertexUv;
layout(location = 2) in vec3 vertexNormalModelspace;

out vec2 UV;
out vec3 dirLightCamSpace;
out vec3 posWorldspace;
out vec3 normalCamspace;
out vec3 eyeDirectionCamspace;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform vec3 directionalLightrot;

// Second texture coords
// varying vec2 vTexCoords;

void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position = MVP * vec4(vertexPositionModelspace, 1.0);
	// vTexCoords = vertexUv;

	posWorldspace = vec4(M * vec4(vertexNormalModelspace, 1.0)).xyz;

	vec3 vertexPosCamSpace = (V * M * vec4(vertexPositionModelspace, 1.0)).xyz;
	eyeDirectionCamspace = vec3(0.0) - vertexPosCamSpace;

	vec3 lightPos = (V * vec4(directionalLightrot, 1.0)).xyz;
	// vec3 lightPos = (V * vec4(1.0)).xyz;
	dirLightCamSpace = lightPos + eyeDirectionCamspace;

	normalCamspace = normalize((V * M * vec4(vertexNormalModelspace, 0.0)).xyz);

	// The color of each vertex will be interpolated
	// to produce the color of each fragment
	UV = vertexUv;
}