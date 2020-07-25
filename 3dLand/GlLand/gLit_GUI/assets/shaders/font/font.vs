#version 440 core

layout (location = 0) in vec4 inVertex;
out vec2 oTexCoords;

uniform mat4 projection;

void main() {
  gl_position = projection * vec4(vertex.xy, 0.0, 1.0);
  oTexCoords = vertex.zw;
};