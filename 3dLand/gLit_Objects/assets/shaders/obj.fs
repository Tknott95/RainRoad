#version 440 core

out vec4 FragColor;

in vec4 VertexColor;
// in vec3 Position;

void main() {
  FragColor = VertexColor;
}