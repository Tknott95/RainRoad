#version 440 core

out vec4 FragColor;

in vec4 VertexColor;
// in vec3 Position;
in vec2 TexCoords;
in vec3 oShaderColorChange;

uniform sampler2D myTexture;

//  vec4 can have vec3 input for collision changing color on this AABB
void main() {
  FragColor = texture(myTexture, TexCoords) * vec4(oShaderColorChange, 1.0); //VertexColor;
}