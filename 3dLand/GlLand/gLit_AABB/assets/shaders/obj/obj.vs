#version 440 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 uvCoords;

out vec4 VertexColor;
out vec2 TexCoords;
// out vec3 Position;
out vec3 oShaderColorChange;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 uShaderColorChange;

void main() {
  oShaderColorChange = uShaderColorChange;
  gl_Position = projection * view * model * transform * vec4(aPos, 1.0);
  VertexColor = vec4(0.3, 0.3, 3.0, 1.0);
  TexCoords = vec2(uvCoords.x, uvCoords.y);
}