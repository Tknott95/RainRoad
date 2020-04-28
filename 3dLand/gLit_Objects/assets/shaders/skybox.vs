#version 440 core

layout (location = 0) in vec3 posData;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main() {
  TexCoords = posData;
  gl_Position = projection * view * vec4(posData, 1.0);
}
