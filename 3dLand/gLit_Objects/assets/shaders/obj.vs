#version 440 core

layout (location = 0) in vec3 aPos;

out vec4 VertexColor;
// out vec3 Position;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
  gl_Position = projection * view * model * transform * vec4(aPos, 1.0);
  // Position = vec3(model * vec4(aPos, 1.0));
  VertexColor = vec4(0.3, 0.3, 3.0, 1.0); 
}