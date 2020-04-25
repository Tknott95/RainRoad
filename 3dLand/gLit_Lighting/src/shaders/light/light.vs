#version 440 core
layout (location = 0) in vec3 posData;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
// projection * view
void main() {
  gl_Position = projection * view * model * vec4(posData, 1.0);
}