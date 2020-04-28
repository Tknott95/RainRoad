#version 440 core

layout (location = 0) in vec3 posData;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main() {
  Texcoords = posData;
  gl_position = projection * view * vec4(posData, 1.0);
}
