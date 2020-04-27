#version 440 core
layout (location = 0) in vec3 posData;
layout (location = 1) in vec3 normalData;
layout (location = 2) in vec2 texData;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

void main() {
  FragPos = vec3(/*transform */model * vec4(posData, 1.0));
  Normal = mat3(transpose(inverse(model))) * normalData;
  TexCoords = texData;

  gl_Position = projection * view  * vec4(FragPos, 1.0);
}